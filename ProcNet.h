#ifndef PROCSOCK_PROCNET_H
#define PROCSOCK_PROCNET_H

#include <string>
#include <unordered_map>
#include <vector>
#include "NetData.h"

using namespace std;

class ProcNet {
private:
    string ipType;

public:
    ProcNet(string ipType) : ipType(ipType) { }

    unordered_map<string, NetData> getInodesIpMap();

private:
    unordered_map<string, NetData> retrieveInodeIpMapping();
    pair<string, NetData> extractInodeIpMapping(const string &ipTypeData);
};


#endif //PROCSOCK_PROCNET_H
