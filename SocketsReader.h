#ifndef PROCSOCK_SOCKETSREADER_H
#define PROCSOCK_SOCKETSREADER_H


#include "NetDataAll.h"


using namespace std;

class SocketsReader {
public:
    SocketsReader(unsigned short processId) : processId(processId) { }

    NetDataAll Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_SOCKETSREADER_H
