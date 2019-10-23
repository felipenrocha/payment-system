#include "../../include/autenticacaoInterface.hpp"

AutenticacaoInterface::AutenticacaoInterface(int option)
{
    switch (option)
    {
    case 1:
        this->login();
        break;
    case 2:
        this->registrar();
        break;
    default:
        break;
    }
}
AutenticacaoInterface::~AutenticacaoInterface()
{
}

void AutenticacaoInterface::create()
{
}
void AutenticacaoInterface::remove()
{
}
void AutenticacaoInterface::update()
{
}

void AutenticacaoInterface::login()
{
    cout << "login sucedido" << endl;
}

void AutenticacaoInterface::registrar()
{
    cout << "register sucedido" << endl;
}