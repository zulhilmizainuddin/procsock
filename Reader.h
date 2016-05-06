#ifndef PROCSOCK_READER_H
#define PROCSOCK_READER_H


#include <vector>
#include "NetData.h"

class Reader {
public:
    virtual vector<NetData> Read() = 0;
};

#endif //PROCSOCK_READER_H
