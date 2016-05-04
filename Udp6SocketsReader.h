#ifndef PROCSOCK_UDP6SOCKETSREADER_H
#define PROCSOCK_UDP6SOCKETSREADER_H


#include <vector>
#include "NetData.h"

class Udp6SocketsReader {
public:
    Udp6SocketsReader(unsigned short processId) : processId(processId) { }

    vector<NetData> Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_UDP6SOCKETSREADER_H
