#include "../../include/jogoInterface.hpp"

JogoInterface::JogoInterface(sqlite3 *database)
{
    // cout << "in";
    this->db = database;
    this->gerenciar();
}


void JogoInterface::gerenciar()
{

    JogoRepository *jogoRepository = new JogoRepository(this->getDB());
    int operacao;
    do
    {
        operacao = printMenuGerenciar("Jogo");
        switch (operacao)
        {
        case 1:
            jogoRepository->get();
            break;
        case 2:
            jogoRepository->add();
            break;
        case 3:
            jogoRepository->remove();
            break;
        case 4:
            jogoRepository->update();
            break;
        default:
            break;
        }
    } while (operacao >= 1 && operacao <= 4);
}