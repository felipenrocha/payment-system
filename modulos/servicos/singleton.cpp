#include "../../include/singleton.hpp"

Singleton *Singleton::instancia = 0;

Singleton *Singleton::getInstancia()
{
    cout << "singleton" << endl;

    if (instancia == 0)
    {
        instancia = new Singleton();
    }

    return instancia;
}
Singleton::Singleton()
{
}