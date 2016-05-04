#ifndef PROCSOCK_SOCKETINFO_H
#define PROCSOCK_SOCKETINFO_H


#include <vector>
#include "NetData.h"
#include "NetDataAll.h"

using namespace std;

class SocketInfo {
public:
    virtual NetDataAll readAllSockets() = 0;
    virtual vector<NetData> readIpv4TcpSockets() = 0;
    virtual vector<NetData> readIpv4UdpSockets() = 0;
    virtual vector<NetData> readIpv6TcpSockets() = 0;
    virtual vector<NetData> readIpv6UdpSockets() = 0;
};

#endif //PROCSOCK_SOCKETINFO_H
