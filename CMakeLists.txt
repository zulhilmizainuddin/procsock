cmake_minimum_required(VERSION 3.3)
project(procsock)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -fopenmp")

set(SOURCE_FILES
        HexToIp.cpp HexToIp.h
        InodeIpHelper.cpp InodeIpHelper.h
        main.cpp
        NetData.h
        NetDataAll.h
        ProcFd.cpp ProcFd.h
        ProcessId.cpp ProcessId.h
        ProcNet.cpp ProcNet.h
        ProcSock.cpp ProcSock.h
        SocketInfo.h
        SocketsReader.cpp SocketsReader.h
        TcpSocketsReader.cpp TcpSocketsReader.h
        Tcp6SocketsReader.cpp Tcp6SocketsReader.h
        UdpSocketsReader.cpp UdpSocketsReader.h
        Udp6SocketsReader.cpp Udp6SocketsReader.h)

add_library(procsock-shared SHARED ${SOURCE_FILES})
add_library(procsock-static STATIC ${SOURCE_FILES})

set_target_properties(procsock-shared PROPERTIES OUTPUT_NAME procsock)
set_target_properties(procsock-static PROPERTIES OUTPUT_NAME procsock)

#add_executable(procsock ${SOURCE_FILES})