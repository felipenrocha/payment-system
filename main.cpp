#include <iostream>
#include "usuario.hpp"
#include "jogo.hpp"
#include "partida.hpp"

using namespace std;

int main()
{

    // Usuario user1 = cadastraUsuario();
    // try
    // {
    //     Jogo jogo1("111", "Brasil x Argentina", "Brasilia", "AM", 1);
    //     cout << "Código do Jogo: " << jogo1.getCodigo() << endl;
    //     cout << "Nome do Jogo: " << jogo1.getNome() << endl;
    //     cout << "Cidade do Jogo: " << jogo1.getCidade() << endl;
    //     cout << "Estado: " << jogo1.getEstado() << endl;
    //     cout << "Tipo do Jogo: " << jogo1.getTipoDoJogo() << endl;
    // }
    // catch (invalid_argument e)
    // {
    //     cout << e.what() << endl;
    // }

    try

    {
        Partida partida1(10,"22/11/98", "15:00", 25.45, 25);
        cout << "Numero da sala: " << partida1.getNumeroSala() << endl;
        cout << "DATA: " << partida1.getData() << endl;
        cout << "Horário: " << partida1.getHorario() << endl;
        cout << "Preço: " << partida1.getPreco() << endl;
        cout << "Disponibilidade: " << partida1.getDisponibilidade() << endl;
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
