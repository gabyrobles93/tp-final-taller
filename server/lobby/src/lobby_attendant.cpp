#include "lobby_attendant.h"
#include "thread.h"
#include "client.h"
#include "yaml.h"

LobbyAttendant::LobbyAttendant(Client * c, ProtectedMatchsStatus & pms) :
client(c),
matchs_status(pms) {
    this->keep_running = true;
}

bool LobbyAttendant::isRunning(void) const {
    return this->keep_running;
}

size_t LobbyAttendant::getId(void) const {
    return 0;
}

void LobbyAttendant::stop(void) {
    this->keep_running = false;
}

void LobbyAttendant::run(void) {
    while (this->keep_running) {
        Event new_event = this->client->rcvEvent();
        if (new_event.quit()) {
            std::cout << "El cliente " << this->client->getPlayerName() << " ha saldo del lobby." << std::endl;
            this->client->setStatus(quited);
            this->keep_running = false;
            return;
        }

        std::cout << "Evento recibido del cliente " << this->client->getPlayerName() << std::endl;
        processEvent(new_event);
    }
}

void LobbyAttendant::processEvent(Event & event) {
    YAML::Node event_node = event.getNode();
    action_t action = (action_t) event_node["event"]["action"].as<int>();

    switch(action) {
        case a_refreshLobby: 
            this->client->sendGamesStatus(this->matchs_status.getMatchsStatus());
            break;
        case a_createMatch:
            std::cout << "El cliente " << this->client->getPlayerName() << " ha creado una partida." << std::endl;
            this->client->setStatus(creator);
            break;

        default:
            break;
    }
}