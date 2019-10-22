#include "../../include/menu.hpp"

Menu::Menu()
{
    telaInicial();
}

void Menu::telaInicial()
{
    cout << "Bem-Vindo ao Sistema de Vendas e Consulta de Ingressos!" << endl;
    int input;

    do
    {
        cout << "Selecione uma opcão:" << endl;
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
        login();
    }
    else if (input == 2)
    {
        registrar();
    }
}
void Menu::login()
{
    cout << "login" << endl;
}
void Menu::registrar()
{
    cout << "registrar" << endl;
}