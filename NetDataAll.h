#ifndef PROCSOCK_NETDATAALL_H
#define PROCSOCK_NETDATAALL_H

#include <vector>
#include "NetData.h"

using namespace std;

struct NetDataAll {
    vector<NetData> tcpNetData;
    vector<NetData> udpNetData;
    vector<NetData> tcp6NetData;
    vector<NetData> udp6NetData;
};

#endif //PROCSOCK_NETDATAALL_H
