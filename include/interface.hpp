#ifndef __INTERFACE__
#define __INTERFACE__
#include "singleton.hpp"

class Interface : public Singleton
{
public:
    virtual void create(Singleton *instancia);
    virtual void remove(Singleton *instancia);
    virtual void update(Singleton *instancia);
    virtual Singleton *get()
    {
        return this->getInstancia();
    }
    virtual ~Interface();

private:
    Interface(Singleton *object);
};

#endif