#include "../../include/apresentacaoCartao.hpp"

string ApresentacaoCartao::getIdtoRemove()
{
    string id;
    cout << "Digite o ID do Cartao a ser removido:";
    cin >> id;

    return id;
}

string ApresentacaoCartao::getIdtoUpdate()
{
    string id;
    cout << "Digite o ID do Cartao a ser editado:";
    cin >> id;

    return id;
}

int ApresentacaoCartao::getFieldToUpdate()
{
    int operacao = -1;
    do
    {
        cout << "Selecione uma opção para editar: "
             << endl
             << "1) Editar Numero " << endl
             << "2) Editar Codigo " << endl
             << "3) Editar Data de Validade " << endl;
        cin >> operacao;

    } while (operacao < 1 || operacao > 3);
    return operacao;
}