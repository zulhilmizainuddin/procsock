#ifndef PROCSOCK_READERALL_H
#define PROCSOCK_READERALL_H


#include "NetDataAll.h"

class ReaderAll {
public:
    virtual NetDataAll Read() = 0;
};

#endif //PROCSOCK_READERALL_H
