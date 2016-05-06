#ifndef PROCSOCK_SOCKETSREADER_H
#define PROCSOCK_SOCKETSREADER_H


#include "NetDataAll.h"
#include "ReaderAll.h"


using namespace std;

class SocketsReader : public ReaderAll {
public:
    SocketsReader(unsigned short processId) : processId(processId) { }

    virtual NetDataAll Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_SOCKETSREADER_H
