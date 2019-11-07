#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include <sqlite3.h>

class Interface
{
private:


public:
    virtual void gerenciar() = 0;
};

#endif