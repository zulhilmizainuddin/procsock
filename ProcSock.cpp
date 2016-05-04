#include "SocketsReader.h"
#include "ProcessId.h"
#include "ProcSock.h"


ProcSock::ProcSock(unsigned int processId) throw(invalid_argument) : processId(processId) {
    try {
        if (processId > 65535) {
            throw invalid_argument("process id " + to_string(processId) + " out of range");
        }
    }
    catch (invalid_argument ex) {
        throw invalid_argument("process id " + to_string(processId) + " does not exist");
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


NetDataAll ProcSock::readAllSockets() {
    return SocketsReader(processId).Read();
}

vector<NetData> ProcSock::readIpv4TcpSockets() {

}

vector<NetData> ProcSock::readIpv4UdpSockets() {

}

vector<NetData> ProcSock::readIpv6TcpSockets() {

}

vector<NetData> ProcSock::readIpv6UdpSockets() {

}
