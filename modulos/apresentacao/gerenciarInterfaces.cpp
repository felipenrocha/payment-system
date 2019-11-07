#include "../../include/gerenciarInterface.hpp"
int printMenuGerenciar(string repository)
{
    int input = -1;
    do
    {
        cout << "Selecione uma das opções: " << endl
             << "1) Ver Lista de " << repository << "s" << endl
             << "2) Criar " << repository << endl
             << "3) Remover " << repository << endl
             << "4) Editar " << repository << endl
             << "5) Sair " << endl;
        cin >> input;
        if (input < 1 || input > 5)
        {
            cout << "Por favor, selecione uma opção válida!" << endl;
        }

    } while (input < 1 || input > 5);
    return input;
}