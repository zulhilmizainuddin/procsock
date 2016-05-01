#ifndef PROCSOCK_PROCESSID_H
#define PROCSOCK_PROCESSID_H


#include <string>

using namespace std;

class ProcessId {
public:
    string getProcessId(const string &processName);

private:
    string retrieveProcessId(const string &processName);
};


#endif //PROCSOCK_PROCESSID_H
