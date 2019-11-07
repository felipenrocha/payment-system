#include "../../include/cartaoInterface.hpp"
#include "../../include/cartaoInterface.hpp"

CartaoInterface::CartaoInterface(sqlite3 *database)
{
    // cout << "in";
    this->db = database;
    this->gerenciar();
}


void CartaoInterface::gerenciar()
{

    CartaoRepository *cartaoRepository = new CartaoRepository(this->getDB());
    int operacao;
    do
    {
        operacao = printMenuGerenciar("Cartao");
        switch (operacao)
        {
        case 1:
            cartaoRepository->get();
            break;
        case 2:
            cartaoRepository->add();
            break;
        case 3:
            cartaoRepository->remove();
            break;
        case 4:
            cartaoRepository->update();
            break;
        default:
            break;
        }
    } while (operacao >= 1 && operacao <= 4);
}