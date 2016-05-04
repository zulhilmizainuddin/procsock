#include "SocketsReader.h"
#include "InodeIpHelper.h"
#include "ProcNet.h"
#include "ProcFd.h"
#include "HexToIp.h"

NetDataAll SocketsReader::Read() {
    unordered_map<string, NetData> tcpInodeIp;
    unordered_map<string, NetData> udpInodeIp;
    unordered_map<string, NetData> tcp6InodeIp;
    unordered_map<string, NetData> udp6InodeIp;

    vector<string> socketsInode = ProcFd(to_string(processId)).getSocketInodeList();

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

    vector<NetData> tcpNetData;
    vector<NetData> udpNetData;
    vector<NetData> tcp6NetData;
    vector<NetData> udp6NetData;

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

    NetDataAll netDataAll;

    #pragma  omp parallel
    {
        #pragma omp for
        for (int i = 0; i < tcpNetData.size(); ++i) {
            NetData convertedNetData;

            convertedNetData.localIp = HexToIp::convertHexToIpv4(tcpNetData[i].localIp);
            convertedNetData.remoteIp = HexToIp::convertHexToIpv4(tcpNetData[i].remoteIp);

            convertedNetData.localPort = HexToIp::convertHexToPort(tcpNetData[i].localPort);
            convertedNetData.remotePort = HexToIp::convertHexToPort(tcpNetData[i].remotePort);

            netDataAll.tcpNetData.push_back(convertedNetData);
        }

        #pragma omp for
        for (int i = 0; i < udpNetData.size(); ++i) {
            NetData convertedNetData;

            convertedNetData.localIp = HexToIp::convertHexToIpv4(udpNetData[i].localIp);
            convertedNetData.remoteIp = HexToIp::convertHexToIpv4(udpNetData[i].remoteIp);

            convertedNetData.localPort = HexToIp::convertHexToPort(udpNetData[i].localPort);
            convertedNetData.remotePort = HexToIp::convertHexToPort(udpNetData[i].remotePort);

            netDataAll.udpNetData.push_back(convertedNetData);
        }

        #pragma omp for
        for (int i = 0; i < tcp6NetData.size(); ++i) {
            NetData convertedNetData;

            convertedNetData.localIp = HexToIp::convertHexToIpv6(tcp6NetData[i].localIp);
            convertedNetData.remoteIp = HexToIp::convertHexToIpv6(tcp6NetData[i].remoteIp);

            convertedNetData.localPort = HexToIp::convertHexToPort(tcp6NetData[i].localPort);
            convertedNetData.remotePort = HexToIp::convertHexToPort(tcp6NetData[i].remotePort);

            netDataAll.tcp6NetData.push_back(convertedNetData);
        }

        #pragma omp for
        for (int i = 0; i < udp6NetData.size(); ++i) {
            NetData convertedNetData;

            convertedNetData.localIp = HexToIp::convertHexToIpv6(udp6NetData[i].localIp);
            convertedNetData.remoteIp = HexToIp::convertHexToIpv6(udp6NetData[i].remoteIp);

            convertedNetData.localPort = HexToIp::convertHexToPort(udp6NetData[i].localPort);
            convertedNetData.remotePort = HexToIp::convertHexToPort(udp6NetData[i].remotePort);

            netDataAll.udp6NetData.push_back(convertedNetData);
        }
    }

    return netDataAll;
}
