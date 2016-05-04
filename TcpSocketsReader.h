#ifndef PROCSOCK_TCPSOCKETSREADER_H
#define PROCSOCK_TCPSOCKETSREADER_H


#include <vector>
#include "NetData.h"

class TcpSocketsReader {
public:
    TcpSocketsReader(unsigned short processId) : processId(processId) { }

    vector<NetData> Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_TCPSOCKETSREADER_H
