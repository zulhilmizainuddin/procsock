cmake_minimum_required(VERSION 3.3)
project(ProcSock)

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
        SocketsReader.cpp SocketsReader.h)
add_executable(ProcSock ${SOURCE_FILES})