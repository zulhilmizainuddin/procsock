#ifndef PROCSOCK_PROCSOCK_H
#define PROCSOCK_PROCSOCK_H


#include <string>
#include <vector>
#include "NetData.h"
#include "ProcessId.h"
#include "SocketIp.h"


using namespace std;

class ProcSock : public SocketIp {
public:
    ProcSock(unsigned short processId) : processId(processId) { }

    ProcSock(const string &processName) : processName(processName) {
        processId = static_cast<unsigned short>(stoul(ProcessId().getProcessId(processName)));
    }

    virtual void readOpenedSocketsIp();
    virtual vector<NetData> getTcp4SocketsInfo();
    virtual vector<NetData> getUdp4SocketsInfo();
    virtual vector<NetData> getTcp6SocketsInfo();
    virtual vector<NetData> getUdp6SocketsInfo();

private:
    unsigned short processId;
    string processName;

    vector<NetData> tcpNetData;
    vector<NetData> udpNetData;
    vector<NetData> tcp6NetData;
    vector<NetData> udp6NetData;
};


#endif //PROCSOCK_PROCSOCK_H
