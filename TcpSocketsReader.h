#ifndef PROCSOCK_TCPSOCKETSREADER_H
#define PROCSOCK_TCPSOCKETSREADER_H


#include <vector>
#include "NetData.h"
#include "Reader.h"

class TcpSocketsReader : public Reader {
public:
    TcpSocketsReader(unsigned short processId) : processId(processId) { }

    virtual vector<NetData> Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_TCPSOCKETSREADER_H
