#include "../../include/partidaInterface.hpp"

PartidaInterface::PartidaInterface(sqlite3 *database)
{
    // cout << "in";
    this->db = database;
    this->gerenciar();
}


void PartidaInterface::gerenciar()
{

    PartidaRepository *partidaRepository = new PartidaRepository(this->getDB());
    int operacao;
    do
    {
        operacao = printMenuGerenciar("Partida");
        switch (operacao)
        {
        case 1:
            partidaRepository->get();
            break;
        case 2:
            partidaRepository->add();
            break;
        case 3:
            partidaRepository->remove();
            break;
        case 4:
            partidaRepository->update();
            break;
        default:
            break;
        }
    } while (operacao >= 1 && operacao <= 4);
}

