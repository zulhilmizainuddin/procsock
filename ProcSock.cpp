#include <unordered_map>
#include "HexToIp.h"
#include "InodeIpHelper.h"
#include "ProcFd.h"
#include "ProcNet.h"
#include "ProcSock.h"


ProcSock::ProcSock(unsigned int processId) throw(invalid_argument) : processId(processId) {
    if (processId > 65535) {
        throw invalid_argument("process id " + to_string(processId) + " out of range");
    }
}

ProcSock::ProcSock(const string &processName) throw(invalid_argument) : processName(processName) {
    try {
        processId = static_cast<unsigned int>(stoul(ProcessId().getProcessId(processName)));
    }
    catch (invalid_argument ex) {
        throw invalid_argument("process " + processName + " does not exist");
    }
}

bool ProcSock::readOpenedSocketsIp() {
    unordered_map<string, NetData> tcpInodeIp;
    unordered_map<string, NetData> udpInodeIp;
    unordered_map<string, NetData> tcp6InodeIp;
    unordered_map<string, NetData> udp6InodeIp;

    vector<string> socketsInode;
    try {
        socketsInode = ProcFd(to_string(processId)).getSocketInodeList();
    }
    catch (invalid_argument ex) {
        return false;
    }

    #pragma omp parallel sections
    {
        #pragma omp section
        tcpInodeIp = ProcNet("tcp").getInodesIpMap();

        #pragma omp section
        udpInodeIp = ProcNet("udp").getInodesIpMap();

        #pragma omp section
        tcp6InodeIp = ProcNet("tcp6").getInodesIpMap();

        #pragma omp section
        udp6InodeIp = ProcNet("udp6").getInodesIpMap();
    }

    #pragma omp parallel sections
    {
        #pragma omp section
        tcpNetData = InodeIpHelper::filterProccessIp(socketsInode, tcpInodeIp);

        #pragma omp section
        udpNetData = InodeIpHelper::filterProccessIp(socketsInode, udpInodeIp);

        #pragma omp section
        tcp6NetData = InodeIpHelper::filterProccessIp(socketsInode, tcp6InodeIp);

        #pragma omp section
        udp6NetData = InodeIpHelper::filterProccessIp(socketsInode, udp6InodeIp);
    }

    return true;
}


vector<NetData> ProcSock::getTcp4SocketsInfo() {
    vector<NetData> netDataList;

    for (auto& netData: tcpNetData) {
        NetData convertedNetData;

        convertedNetData.localIp = HexToIp::convertHexToIpv4(netData.localIp);
        convertedNetData.remoteIp = HexToIp::convertHexToIpv4(netData.remoteIp);

        convertedNetData.localPort = HexToIp::convertHexToPort(netData.localPort);
        convertedNetData.remotePort = HexToIp::convertHexToPort(netData.remotePort);

        netDataList.push_back(convertedNetData);
    }

    return netDataList;
}

vector<NetData> ProcSock::getUdp4SocketsInfo() {
    vector<NetData> netDataList;

    for (auto& netData: udpNetData) {
        NetData convertedNetData;

        convertedNetData.localIp = HexToIp::convertHexToIpv4(netData.localIp);
        convertedNetData.remoteIp = HexToIp::convertHexToIpv4(netData.remoteIp);

        convertedNetData.localPort = HexToIp::convertHexToPort(netData.localPort);
        convertedNetData.remotePort = HexToIp::convertHexToPort(netData.remotePort);

        netDataList.push_back(convertedNetData);
    }

    return netDataList;
}

vector<NetData> ProcSock::getTcp6SocketsInfo() {
    vector<NetData> netDataList;

    for (auto& netData: tcp6NetData) {
        NetData convertedNetData;

        convertedNetData.localIp = HexToIp::convertHexToIpv6(netData.localIp);
        convertedNetData.remoteIp = HexToIp::convertHexToIpv6(netData.remoteIp);

        convertedNetData.localPort = HexToIp::convertHexToPort(netData.localPort);
        convertedNetData.remotePort = HexToIp::convertHexToPort(netData.remotePort);

        netDataList.push_back(convertedNetData);
    }

    return netDataList;
}

vector<NetData> ProcSock::getUdp6SocketsInfo() {
    vector<NetData> netDataList;

    for (auto& netData: udp6NetData) {
        NetData convertedNetData;

        convertedNetData.localIp = HexToIp::convertHexToIpv6(netData.localIp);
        convertedNetData.remoteIp = HexToIp::convertHexToIpv6(netData.remoteIp);

        convertedNetData.localPort = HexToIp::convertHexToPort(netData.localPort);
        convertedNetData.remotePort = HexToIp::convertHexToPort(netData.remotePort);

        netDataList.push_back(convertedNetData);
    }

    return netDataList;
}
