#include "../../include/interface.hpp"

Interface::Interface(Singleton *object)
    : Singleton()
{
    this->instancia = object;
}