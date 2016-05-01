#ifndef PROCSOCK_HEXTOIP_H
#define PROCSOCK_HEXTOIP_H

#include <string>

using namespace std;

class HexToIp {
public:
    static string convertHexToIpv4(const string& hexIp);
    static string convertHexToIpv6(const string& hexIp);
    static string convertHexToPort(const string& hexPort);
};


#endif //PROCSOCK_HEXTOIP_H
