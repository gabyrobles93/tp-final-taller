#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <arpa/inet.h>
#include "protocol.h"
#include "socket.h"
#include "socket_error.h"
#include "protocol_error.h"

#define MSG_PROTOCOL_CLOSE_PEER "El servidor cerró el socket. "

Protocol::Protocol(SocketReadWrite socket) : skt(std::move(socket)) {
}

void Protocol::getPlayerName(std::string & name) {
    uint32_t length;
    uchar playername[PLAYER_NAME_LENGTH_LIMIT];

    this->skt.getBuffer((uchar*)&length, 4);
    length = ntohl(length);

    this->skt.getBuffer(playername, length);
    std::string ret_name((char*) playername, (int)length);
    name = ret_name;    
}

void Protocol::sendName(std::string const & name) const {
    uint32_t length = name.size();
    length = htonl(length);
    this->skt.sendBuffer((const uchar*)&length, 4);
    this->skt.sendBuffer((const uchar*)name.c_str(), name.size());
}

void Protocol::sendFile(std::fstream & file) const {
    uint32_t length;

    file.seekg(0, std::ios::end);
    length = file.tellg();
    file.seekg(0, std::ios_base::beg);
    uint32_t net_length = htonl(length);
    this->skt.sendBuffer((const uchar*)&net_length, 4);

    int remain = length;
    int readed = 0;
    uchar file_chop[FILE_TRANSFER_CHOP_SIZE];
    while (remain) {
        if (remain < FILE_TRANSFER_CHOP_SIZE) {
            file.read((char*)file_chop, remain);
            readed = remain;
        } else {
            file.read((char*)file_chop, FILE_TRANSFER_CHOP_SIZE);
            readed = FILE_TRANSFER_CHOP_SIZE;
        }
        remain -= readed;
        this->skt.sendBuffer(file_chop, readed);
    }
}

void Protocol::rcvFile(std::fstream & file) const {
    uint32_t length = 0;
    this->skt.getBuffer((uchar*)&length, 4);
    length = ntohl(length);

    if (length == 0) {
            std::stringstream msg;
            msg << MSG_PROTOCOL_CLOSE_PEER << std::strerror(errno);
            throw ProtocolError(msg.str());
    }

    int remain = length;
    int received = 0;
    uchar file_chop[FILE_TRANSFER_CHOP_SIZE];
    while (remain) {
        if (remain < FILE_TRANSFER_CHOP_SIZE) {
            received = this->skt.getBuffer(file_chop, remain);
        } else {
            received = this->skt.getBuffer(file_chop, FILE_TRANSFER_CHOP_SIZE);
        }
        remain -= received;
        file.write((char*)file_chop, received);
    }
}

void Protocol::sendExit(void) {
    this->skt.shutDown();
}

void Protocol::rcvGameMap(YAML::Node & mapNode) {
    uint32_t node_size = 0;
    skt.getBuffer((uchar *) &node_size, 4);
    node_size = ntohl(node_size);
    uchar * buffer = new uchar[node_size+1];
    skt.getBuffer(buffer, node_size);
    buffer[node_size] = '\0';
    std::string text_node((char*) buffer);
    delete buffer;

    mapNode = YAML::Load(text_node);
}

void Protocol::sendGameMap(YAML::Node & mapNode) {
    std::stringstream map_dump;
    map_dump << mapNode;
    std::cout << map_dump.str() << std::endl;
    uint32_t node_size = map_dump.str().length();
    uint32_t net_node_size = htonl(node_size);
    skt.sendBuffer((const uchar *) &net_node_size, 4);
    skt.sendBuffer((const uchar *) map_dump.str().c_str(), node_size);
}

void Protocol::sendEvent(action_t action) {
    this->skt.sendBuffer((const uchar*)&action, 1);
}

void Protocol::rcvEvent(action_t & action) {
    this->skt.getBuffer((uchar*)&action, 1);
}

void Protocol::sendModel(YAML::Node & modelNode) {
    this->sendGameMap(modelNode);
}

void Protocol::rcvModel(YAML::Node & modelNode) {
    this->rcvGameMap(modelNode);
}
