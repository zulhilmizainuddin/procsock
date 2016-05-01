#ifndef PROCSOCK_NETDATA_H
#define PROCSOCK_NETDATA_H

#include <string>

using namespace std;

struct NetData {
    string localIp;
    string localPort;
    string remoteIp;
    string remotePort;
};

#endif //PROCSOCK_NETDATA_H
