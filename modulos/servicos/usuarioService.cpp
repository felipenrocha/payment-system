#include "../../include/usuarioInterface.hpp"

UsuarioInterface::UsuarioInterface() : Interface()
{

    this->autenticacao();
}

UsuarioInterface::~UsuarioInterface()
{
}

void UsuarioInterface::autenticacao()
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
    cout << "Selecione uma das opções: " << endl;
    cout << "1) Remover Usuario" << endl;
    cout << "2) Editar Usuário" << endl;
}
bool UsuarioInterface::loginUsuario()
{
    cout << "login";
}
bool UsuarioInterface::registrarUsuario()
{
    cout << "registrar";
}
