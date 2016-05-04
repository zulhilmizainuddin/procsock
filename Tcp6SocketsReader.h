#ifndef PROCSOCK_TCP6SOCKETSREADER_H
#define PROCSOCK_TCP6SOCKETSREADER_H


#include <vector>
#include "NetData.h"

class Tcp6SocketsReader {
public:
    Tcp6SocketsReader(unsigned short processId) : processId(processId) { }

    vector<NetData> Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_TCP6SOCKETSREADER_H
