#include "../../include/singleton.hpp"

Singleton *Singleton::instancia = 0;

Singleton *Singleton::getInstancia()
{
    if (instancia == 0)
    {
        instancia = new Singleton();
    }

    return instancia;
}
Singleton::Singleton()
{
}