#include <unordered_map>
#include "HexToIp.h"
#include "InodeIpHelper.h"
#include "ProcFd.h"
#include "ProcNet.h"
#include "Udp6SocketsReader.h"

vector<NetData> Udp6SocketsReader::Read() {
    vector<string> socketsInode = ProcFd(to_string(processId)).getSocketInodeList();

    unordered_map<string, NetData> udp6InodeIp = ProcNet("udp6").getInodesIpMap();
    vector<NetData> udp6NetData = InodeIpHelper::filterProccessIp(socketsInode, udp6InodeIp);

    vector<NetData> convertedNetDataList;
    for (auto& netData: udp6NetData) {
        NetData convertedNetData;

        convertedNetData.localIp = HexToIp::convertHexToIpv6(netData.localIp);
        convertedNetData.remoteIp = HexToIp::convertHexToIpv6(netData.remoteIp);

        convertedNetData.localPort = HexToIp::convertHexToPort(netData.localPort);
        convertedNetData.remotePort = HexToIp::convertHexToPort(netData.remotePort);

        convertedNetDataList.push_back(convertedNetData);
    }

    return convertedNetDataList;
}
