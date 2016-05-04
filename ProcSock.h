#ifndef PROCSOCK_PROCSOCK_H
#define PROCSOCK_PROCSOCK_H


#include <stdexcept>
#include <string>
#include <vector>
#include "NetData.h"
#include "NetDataAll.h"
#include "SocketInfo.h"


using namespace std;

class ProcSock : public SocketInfo {
public:
    ProcSock(unsigned int processId) throw(invalid_argument);
    ProcSock(const string &processName) throw(invalid_argument);

    virtual NetDataAll readAllSockets();
    virtual vector<NetData> readIpv4TcpSockets();
    virtual vector<NetData> readIpv4UdpSockets();
    virtual vector<NetData> readIpv6TcpSockets();
    virtual vector<NetData> readIpv6UdpSockets();

private:
    unsigned int processId;
    string processName;
};


#endif //PROCSOCK_PROCSOCK_H
