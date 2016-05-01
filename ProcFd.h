#ifndef PROCSOCK_PROCFD_H
#define PROCSOCK_PROCFD_H

#include <fstream>
#include <vector>

using namespace std;

class ProcFd {
private:
    string pid;
public:
    ProcFd(string pid) : pid(pid) { }

    vector<string> getSocketInodeList();

private:
    vector<string> retrieveSocketsInode();
    string extractSocketInode(const string &symlinkContent);
};


#endif //PROCSOCK_PROCFD_H
