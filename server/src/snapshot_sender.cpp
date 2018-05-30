#include "snapshot_sender.h"
#include "socket_error.h"
#include <iostream>

SnapshotSender::SnapshotSender(Queue<YAML::Node> & snapshots, Protocol& protocol) : 
snapshots(snapshots) ,
protocol(protocol) {
    this->keep_running = true;
}

SnapshotSender::~SnapshotSender() {
}

void SnapshotSender::run() {
    while (keep_running) {
        YAML::Node snapshot = this->snapshots.pop();
        this->protocol.sendModel(snapshot);
    }
}

size_t SnapshotSender::getId(void) const{
    return 0;
}

bool SnapshotSender::isRunning(void) const {
    return this->keep_running;
}

void SnapshotSender::stop() {
    this->keep_running = false;
}