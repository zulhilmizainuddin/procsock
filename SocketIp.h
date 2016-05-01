#ifndef PROCSOCK_SOCKETIP_H
#define PROCSOCK_SOCKETIP_H

#include "NetData.h"

class SocketIp {
public:
    virtual void readOpenedSocketsIp() = 0;
    virtual vector<NetData> getTcp4SocketsInfo() = 0;
    virtual vector<NetData> getUdp4SocketsInfo() = 0;
    virtual vector<NetData> getTcp6SocketsInfo() = 0;
    virtual vector<NetData> getUdp6SocketsInfo() = 0;
};

#endif //PROCSOCK_SOCKETIP_H
