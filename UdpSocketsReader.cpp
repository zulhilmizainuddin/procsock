#include <unordered_map>
#include "HexToIp.h"
#include "InodeIpHelper.h"
#include "ProcFd.h"
#include "ProcNet.h"
#include "UdpSocketsReader.h"

vector<NetData> UdpSocketsReader::Read() {
    vector<string> socketsInode = ProcFd(to_string(processId)).getSocketInodeList();

    unordered_map<string, NetData> udpInodeIp = ProcNet("udp").getInodesIpMap();
    vector<NetData> udpNetData = InodeIpHelper::filterProccessIp(socketsInode, udpInodeIp);

    vector<NetData> convertedNetDataList;
    for (auto& netData: udpNetData) {
        NetData convertedNetData;

        convertedNetData.localIp = HexToIp::convertHexToIpv4(netData.localIp);
        convertedNetData.remoteIp = HexToIp::convertHexToIpv4(netData.remoteIp);

        convertedNetData.localPort = HexToIp::convertHexToPort(netData.localPort);
        convertedNetData.remotePort = HexToIp::convertHexToPort(netData.remotePort);

        convertedNetDataList.push_back(convertedNetData);
    }

    return convertedNetDataList;
}
