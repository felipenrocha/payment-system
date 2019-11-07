#include "../../include/apresentacaoUsuario.hpp"


string ApresentacaoUsuario::getIdtoRemove()
{
    string Id;
    cout << "Digite o Id do Usuario a ser removido:";
    cin >> Id;

    return Id;
}

string ApresentacaoUsuario::getIdtoUpdate()
{
    string Id;
    cout << "Digite o Id do Usuario a ser editado:";
    cin >> Id;

    return Id;
}

int ApresentacaoUsuario::getFieldToUpdate()
{
    int operacao = -1;
    do
    {
        cout << "Selecione uma opção para editar: "
             << endl
             << "1) Editar Id " << endl
             << "2) Editar Senha" << endl;
        cin >> operacao;

    } while (operacao != 1 && operacao != 2);
}