#ifndef __INTERFACE__
#define __INTERFACE__
#include <iostream>
#include <string>
#include "singleton.hpp"
using namespace std;

class Interface : public Singleton
{
public:
    virtual void get() = 0;
    virtual void create() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    Interface()
    {
        this->instancia = this->getInstancia();
    };
};

#endif