#include <fstream>
#include <algorithm>
#include <regex>
#include "ProcNet.h"

unordered_map<string, NetData> ProcNet::getInodesIpMap() {
    auto inodeIpMapList = retrieveInodeIpMapping();

    return inodeIpMapList;
}

unordered_map<string, NetData> ProcNet::retrieveInodeIpMapping() {
    string filename = "/proc/net/" + ipType;

    ifstream file(filename);
    string store;
    unordered_map<string, NetData> inodesIpMap;
    inodesIpMap.reserve(100);

    bool firstLine = true;
    while (getline(file, store)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }

        inodesIpMap.insert(move(extractInodeIpMapping(store)));
    }

    return inodesIpMap;
}

pair<string, NetData> ProcNet::extractInodeIpMapping(const string &ipTypeData) {
    regex ipTypeDataRegex("([0-9A-Z]{8,32}+):([0-9A-Z]{4})\\s([0-9A-Z]{8,32}+):([0-9A-Z]{4})(?:\\s++[0-9A-Z:]++){6}\\s([0-9]++)");
    smatch match;

    struct NetData netData;
    if (regex_search(ipTypeData, match, ipTypeDataRegex)) {

        netData = {
                match[1].str().c_str(),
                match[2].str().c_str(),
                match[3].str().c_str(),
                match[4].str().c_str()
        };
    }

    return pair<string, NetData>(match[5].str().c_str(), netData);
}
