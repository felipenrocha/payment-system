#include "../../include/apresentacaoJogo.hpp"

string ApresentacaoJogo::getIdtoRemove()
{
    string id;
    cout << "Digite o Id do Jogo a ser removido: ";
    cin >> id;

    return id;
}

string ApresentacaoJogo::getIdtoUpdate()
{
    string id;
    cout << "Digite o Id do Jogo a ser editado: ";
    cin >> id;

    return id;
}

int ApresentacaoJogo::getFieldToUpdate()
{
    int operacao = -1;
    do
    {
        cout << "Selecione uma opção para editar: "
             << endl
             << "1) Editar Codigo " << endl
             << "2) Editar Nome " << endl
             << "3) Editar Cidade " << endl
             << "4) Editar Estado " << endl
             << "5) Editar Tipo " << endl
             << "6) Sair" << endl;
        cin >> operacao;

    } while (operacao < 1 || operacao >= 6);
    return operacao;
}

void ApresentacaoJogo::printStates()
{
    for (auto const &i : estados)
    {
        cout << i << " ";
    }
    cout << endl;
}
void ApresentacaoJogo::printTipos()
{
    cout << "1) Local" << endl
         << "2) Estadual" << endl
         << "3) Nacional" << endl
         << "4) Internacional" << endl;
}