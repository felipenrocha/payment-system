#ifndef __INTERFACE__
#define __INTERFACE__
#include "singleton.hpp"

class Interface
{
public:
    virtual void create(Interface *instancia);
    virtual void remove(Interface *instancia);
    virtual void update(Interface *instancia);
    virtual Interface *get();
    virtual ~Interface();

protected:
    Interface *instancia;
    Interface(Interface *object);
};

#endif