#include <unordered_map>
#include "HexToIp.h"
#include "InodeIpHelper.h"
#include "ProcFd.h"
#include "ProcNet.h"
#include "TcpSocketsReader.h"

vector<NetData> TcpSocketsReader::Read() {
    vector<string> socketsInode = ProcFd(to_string(processId)).getSocketInodeList();

    unordered_map<string, NetData> tcpInodeIp = ProcNet("tcp").getInodesIpMap();
    vector<NetData> tcpNetData = InodeIpHelper::filterProccessIp(socketsInode, tcpInodeIp);

    vector<NetData> convertedNetDataList;
    for (auto& netData: tcpNetData) {
        NetData convertedNetData;

        convertedNetData.localIp = HexToIp::convertHexToIpv4(netData.localIp);
        convertedNetData.remoteIp = HexToIp::convertHexToIpv4(netData.remoteIp);

        convertedNetData.localPort = HexToIp::convertHexToPort(netData.localPort);
        convertedNetData.remotePort = HexToIp::convertHexToPort(netData.remotePort);

        convertedNetDataList.push_back(convertedNetData);
    }

    return convertedNetDataList;
}
