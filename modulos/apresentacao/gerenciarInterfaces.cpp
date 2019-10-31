#include "../../include/gerenciarInterface.hpp"
int printMenuGerenciar(string interface)
{
    int input = -1;
    do
    {
        cout << "Selecione uma das opções: " << endl
             << "1) Ver Lista de " << interface << "s" << endl
             << "2) Criar " << interface << endl
             << "3) Remover " << interface << endl
             << "4) Editar " << interface << endl
             << "5) Sair " << endl;
        cin >> input;
        if (input < 1 || input > 5)
        {
            cout << "Por favor, selecione uma opção válida!" << endl;
        }

    } while (input < 1 || input > 5);
    return input;
}