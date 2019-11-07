#include "../../include/usuarioInterface.hpp"

UsuarioInterface::UsuarioInterface(sqlite3 *database)
{
    // cout << "in";
    this->db = database;
    this->gerenciar();
}


void UsuarioInterface::gerenciar()
{

    UsuarioRepository *usuarioRepository = new UsuarioRepository(this->getDB());
    int operacao;
    do
    {
        operacao = printMenuGerenciar("Usuario");
        switch (operacao)
        {
        case 1:
            usuarioRepository->get();
            break;
        case 2:
            usuarioRepository->add();
            break;
        case 3:
            usuarioRepository->remove();
            break;
        case 4:
            usuarioRepository->update();
            break;
        default:
            break;
        }
    } while (operacao >= 1 && operacao <= 4);
}