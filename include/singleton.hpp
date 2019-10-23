
#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__
#include <iostream>
#include <string>
#include <ctype.h>
#include <list>
using namespace std;
class Singleton
{
protected:
    static Singleton *instancia;
    Singleton();

public:
    static Singleton *getInstancia();
};

#endif