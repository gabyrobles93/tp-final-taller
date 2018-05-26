#include <unistd.h>
#include <iostream>
#include "SnapshotPusher.h"


SnapshotPusher::SnapshotPusher(World & world, Match & match, Queue<YAML::Node> & snapshots) : 
world(world),
match(match),
snapshots(snapshots)  {
    this->keep_running = true;
}

SnapshotPusher::~SnapshotPusher(){

}

bool SnapshotPusher::isRunning(void) const {
    return true;
}

size_t SnapshotPusher::getId(void) const {
    return 0;
}

void SnapshotPusher::run() {
    while (keep_running) {
        usleep(16666);
        this->snapshot = this->world.getSnapshot();
        this->snapshot["camera"]["worm"] = this->match.getWormTurn(match.getTeamTurn());
        snapshots.push(this->snapshot);
    }
}

void SnapshotPusher::stop() {
    this->keep_running = false;
}