#include "../../include/interface.hpp"

Interface::Interface(Interface *object)
    : Interface()
{
    this->instancia = object;
}
Interface* Interface::instancia = 0;

Interface* Interface::getInstancia()
{
    if (instancia == 0)
    {
        instancia = new Interface();
    }

    return instancia;
}

Interface::Interface()
{}