#include "../../include/autenticacaoInterface.hpp"

AutenticacaoInterface::AutenticacaoInterface(int option)
{
    this->instancia = this->getInstancia();
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
void AutenticacaoInterface::login()
{
    cout << "login sucedido" << endl;
}

void AutenticacaoInterface::registrar()
{
    cout << "register sucedido" << endl;
}