#ifndef PROCSOCK_UDPSOCKETSREADER_H
#define PROCSOCK_UDPSOCKETSREADER_H


#include <vector>
#include "NetData.h"

class UdpSocketsReader {
public:
    UdpSocketsReader(unsigned short processId) : processId(processId) { }

    vector<NetData> Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_UDPSOCKETSREADER_H
