# procsock [![Build Status](https://travis-ci.org/zulhilmizainuddin/procsock.svg?branch=master)](https://travis-ci.org/zulhilmizainuddin/procsock)
C++ library for retrieving ip addresses and ports of opened sockets of a Linux process

## Build
Run build.sh. The project will be built as both shared and static library.

    ./build.sh
    
## Usage
**Get all opened sockets IP addresses and ports of a process**
```cpp
    auto procsock = ProcSock("firefox");
    
    NetDataAll netDataAll = procsock.readAllSockets();
```

**Get IPv4 TCP sockets IP addresses and ports of a process**
```cpp
    auto procsock = ProcSock("firefox");
    
    vector<NetData> netData = procsock.readIpv4TcpSockets();
```

**Get IPv4 UDP sockets IP addresses and ports of a process**
```cpp
    auto procsock = ProcSock("firefox");
    
    vector<NetData> netData = procsock.readIpv4UdpSockets();
```

**Get IPv6 TCP sockets IP addresses and ports of a process**
```cpp
    auto procsock = ProcSock("firefox");
    
    vector<NetData> netData = procsock.readIpv6TcpSockets();
```

**Get IPv6 UDP sockets IP addresses and ports of a process**
```cpp
    auto procsock = ProcSock("firefox");
    
    vector<NetData> netData = procsock.readIpv6UdpSockets();
```
