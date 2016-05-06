#ifndef PROCSOCK_UDPSOCKETSREADER_H
#define PROCSOCK_UDPSOCKETSREADER_H


#include <vector>
#include "NetData.h"
#include "Reader.h"

class UdpSocketsReader : public Reader {
public:
    UdpSocketsReader(unsigned short processId) : processId(processId) { }

    virtual vector<NetData> Read();

private:
    unsigned short processId;
};


#endif //PROCSOCK_UDPSOCKETSREADER_H
