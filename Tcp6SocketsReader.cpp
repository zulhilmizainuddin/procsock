#include <unordered_map>
#include "HexToIp.h"
#include "InodeIpHelper.h"
#include "ProcFd.h"
#include "ProcNet.h"
#include "Tcp6SocketsReader.h"

vector<NetData> Tcp6SocketsReader::Read() {
    vector<string> socketsInode = ProcFd(to_string(processId)).getSocketInodeList();

    unordered_map<string, NetData> tcp6InodeIp = ProcNet("tcp6").getInodesIpMap();
    vector<NetData> tcp6NetData = InodeIpHelper::filterProccessIp(socketsInode, tcp6InodeIp);

    vector<NetData> convertedNetDataList;
    for (auto& netData: tcp6NetData) {
        NetData convertedNetData;

        convertedNetData.localIp = HexToIp::convertHexToIpv6(netData.localIp);
        convertedNetData.remoteIp = HexToIp::convertHexToIpv6(netData.remoteIp);

        convertedNetData.localPort = HexToIp::convertHexToPort(netData.localPort);
        convertedNetData.remotePort = HexToIp::convertHexToPort(netData.remotePort);

        convertedNetDataList.push_back(convertedNetData);
    }

    return convertedNetDataList;
}
