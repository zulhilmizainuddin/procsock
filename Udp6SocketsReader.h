#ifndef PROCSOCK_UDP6SOCKETSREADER_H
#define PROCSOCK_UDP6SOCKETSREADER_H


#include <vector>
#include "NetData.h"
#include "Reader.h"

class Udp6SocketsReader : public Reader {
public:
    Udp6SocketsReader(unsigned short processId) : processId(processId) { }

    virtual vector<NetData> Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_UDP6SOCKETSREADER_H
