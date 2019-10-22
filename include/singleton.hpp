#ifndef __SINGLETON__
#define __SINGLETON__
#include <iostream>

class Singleton
{
protected:
    
    static Singleton *instancia;
    Singleton();

public:
    /* Static access method. */
    static Singleton *getInstancia();
};

#endif