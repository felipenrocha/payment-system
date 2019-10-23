#include "../../include/index.hpp"

Menu::Menu()
{
    this->telaInicial();
}

void Menu::telaInicial()
{
    cout << "Bem-Vindo ao Sistema de Vendas e Consulta de Ingressos!" << endl;
    this->usuarioInterface = new UsuarioInterface();
    this->gerenciarInterfaces();
}

void Menu::gerenciarInterfaces()
{
    int input = -1;
    do
    {
        cout << "Escolha um Domínio para alterar : " << endl
             << "1) Usuário" << endl
             << "2) Cartao"
             << "3) Ingresso" << endl
             << "4) Partida" << endl
             << "5) Jogo" << endl
             << "6) Sair"
             << endl;
        if (input != -1)
        {
            cout << "Digite uma opção válida!" << endl;
        }
    } while (input < 1 && input > 5);
    switch (input)
    {
    case 1:
        usuarioInterface->gerenciar();
        break;
    default:
        break;
    }
}