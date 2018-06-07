#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unistd.h>
#include "yaml.h"
#include "socket.h"
#include "socket_error.h"
#include "protocol.h"
#include "types.h"
#include "World.h"
#include "snapshot_sender.h"
#include "blocking_queue.h"
#include "event.h"
#include "match.h"
#include "event_receiver.h"
#include "Configuration.h"
#include "snapshot.h"

#define PORT "8080"
#define MAP_PATH "mapa_clave/mapa_clave.yml"
#define MAX_QUEUE_SNAPSHOTS 256

Configuration gConfiguration;

int main(/* int argc, char *argv[] */) try {
    SocketListener listener(PORT);
    Protocol protocol(std::move(listener.accept_connection()));
    std::string world_path(MAP_PATH);

    YAML::Node mapNode = YAML::LoadFile(world_path);
    protocol.sendGameMap(mapNode);

    Queue<Snapshot> snapshots(MAX_QUEUE_SNAPSHOTS);
    World world(world_path, snapshots);    
    Match match(world.getWorms(), gConfiguration.TURN_DURATION);

    // Creamos hilos que sacan las fotos y las acolan (SnapshotPusher)
    // y que Mandan las fotos por socket al cliente (SnapshotSender)
    SnapshotSender snapshot_sender(snapshots, match, protocol);
    EventReceiver event_receiver(protocol, world, match, 1);

    // Lanzo hilos
    world.start();
    snapshot_sender.start();
    event_receiver.start();
    
    unsigned int timer = 0;
    match.start(world.getTimeSeconds()); //NO LANZA UN HILO, EMPIEZA LA PARTIDA.
    while(!event_receiver.quitEvent() && !match.finished()) {
        timer = world.getTimeSeconds();
        match.setAliveProjectilesFlag(world.hasAliveProjectiles());
        match.setMovingWormsFlag(world.hasWormsMoving());
        match.setWormsAffectedByExplosion(world.hasWormsAffectedByExplosion());
        match.setProtagonicWormGotHurt(world.hasWormGotHurt(match.getWormTurn(match.getTeamTurn())));
        match.setProtagonicWormDidShoot(world.hasWormShooted(match.getWormTurn(match.getTeamTurn())));
        usleep(16666);
        match.update(world.getTimeSeconds() - timer);
    }

    if (event_receiver.quitEvent()) {
        std::cout << "El cliente cerró la ventana." << std::endl;
    } else if (match.finished()) {
        std::cout << "La partida finalizó y el ganador es " << match.getWinner() << std::endl;
    }
    //Stops y joins de los hilos lanzados
    world.stop();
    snapshot_sender.stop();
    event_receiver.stop();
    snapshot_sender.join();
    world.join();
    event_receiver.join();

    std::cout << "Server finalizado." << std::endl;
    return 0;

} catch(const SocketError & e) {
    std::cout << e.what() << std::endl;
}
