#include <arpa/inet.h>
#include "HexToIp.h"


string HexToIp::convertHexToIpv4(const string &hexIp) {
    char ipBuffer[INET_ADDRSTRLEN];
    struct in_addr ipAddr;

    ipAddr.s_addr = static_cast<uint32_t>(stoul(hexIp, nullptr, 16));

    string ip = inet_ntop(AF_INET, &ipAddr, ipBuffer, INET_ADDRSTRLEN);

    return ip;
}

string HexToIp::convertHexToIpv6(const string &hexIp) {
    char ip6Buffer[INET6_ADDRSTRLEN];
    struct in6_addr ip6Addr;

    sscanf(hexIp.c_str(), "%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx",
           &ip6Addr.s6_addr[3], &ip6Addr.s6_addr[2], &ip6Addr.s6_addr[1], &ip6Addr.s6_addr[0],
           &ip6Addr.s6_addr[7], &ip6Addr.s6_addr[6], &ip6Addr.s6_addr[5], &ip6Addr.s6_addr[4],
           &ip6Addr.s6_addr[11], &ip6Addr.s6_addr[10], &ip6Addr.s6_addr[9], &ip6Addr.s6_addr[8],
           &ip6Addr.s6_addr[15], &ip6Addr.s6_addr[14], &ip6Addr.s6_addr[13], &ip6Addr.s6_addr[12]);

    string ip6 = inet_ntop(AF_INET6, &ip6Addr, ip6Buffer, INET6_ADDRSTRLEN);

    return ip6;
}

string HexToIp::convertHexToPort(const string &hexPort) {
    unsigned short port = static_cast<unsigned short>(stoul(hexPort, nullptr, 16));

    return to_string(port);
}

