#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include <string>
#include "socket.h"

#define PLAYER_NAME_LENGTH_LIMIT 20
#define FILENAME_LENGTH_LIMIT 255
#define FILE_TRANSFER_CHOP_SIZE 255

typedef char Model;

class Protocol {
    private:
        SocketReadWrite skt;

    public:
        explicit Protocol(SocketReadWrite);
        void getPlayerName(std::string &);
        void sendName(std::string const &) const;
        void rcvFile(std::fstream & file) const;
        void sendFile(std::fstream & file) const;
        void sendExitLobby(void);
        void rcvModel(Model &);
};

#endif