#include "../../include/usuarioInterface.hpp"
#include "../../include/gerenciarInterface.hpp"

UsuarioInterface::UsuarioInterface() : Interface()
{
    this->gerenciar();
}

UsuarioInterface::~UsuarioInterface()
{
}

void UsuarioInterface::autenticacao()
{
}
void UsuarioInterface::get()
{
}
void UsuarioInterface::create()
{
}
void UsuarioInterface::remove()
{
}
void UsuarioInterface::update()
{
}
void UsuarioInterface::gerenciar()
{
    int operacao = printMenuGerenciar("Usuario");
    switch (operacao)
    {
    case 1:
        this->get();
        break;
    case 2:
        this->create();
        break;
    case 3:
        this->remove();
        break;
    case 4:
        this->update();
        break;
    default:
        break;
    }
}