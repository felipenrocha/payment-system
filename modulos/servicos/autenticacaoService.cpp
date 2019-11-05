#include "../../include/autenticacaoRepository.hpp"

AutenticacaoRepository::AutenticacaoRepository(int option)
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
AutenticacaoRepository::~AutenticacaoRepository()
{
}
void AutenticacaoRepository::login()
{
    cout << "login sucedido" << endl;
}

void AutenticacaoRepository::registrar()
{
    cout << "register sucedido" << endl;
}