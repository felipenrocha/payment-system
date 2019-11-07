#include "../../include/apresentacaoPartida.hpp"


string ApresentacaoPartida::getIdtoRemove()
{
    string id;
    cout << "Digite o Id da Sala a ser removido: ";
    cin >> id;

    return id;
}

string ApresentacaoPartida::getIdtoUpdate()
{
    string id;
    cout << "Digite o Id da Sala a ser editado: ";
    cin >> id;

    return id;
}

int ApresentacaoPartida::getFieldToUpdate()
{
    int operacao = -1;
    do
    {
        cout << "Selecione uma opção para editar: "
             << endl
             << "1) Editar Id " << endl
             << "2) Editar Data " << endl
             << "3) Editar Preco " << endl
             << "4) Editar HORARIO " << endl
             << "5) Editar Disponibilidade " << endl
             << "6) Sair" << endl;
        cin >> operacao;

    } while (operacao <= 1 || operacao >= 6);
}