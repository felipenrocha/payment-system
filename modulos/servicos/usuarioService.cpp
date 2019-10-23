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

    int input;
    do
    {
        cout << "Selecione uma opção:" << endl;
        cout << "1) Entrar" << endl;
        cout << "2) Cadastrar" << endl;
        cout << "3) Fechar" << endl;
        cin >> input;
        if (input != 1 && input != 2 && input != 3)
        {
            cout << "Por favor, selecione uma opção válida!" << endl;
        }

    } while (input != 1 && input != 2 && input != 3);

    if (input == 1)
    {
        loginUsuario();
    }
    else if (input == 2)
    {
        registrarUsuario();
    }
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
