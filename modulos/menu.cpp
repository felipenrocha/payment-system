#include "../include/index.hpp"
#include "../include/menu.hpp"
Menu::Menu(sqlite3 *db)
{

    this->db = db;
    // this->telaInicial();
    this->gerenciarInterfaces();
}

void Menu::telaInicial()
{
    // cout << "Bem-Vindo ao Sistema de Vendas e Consulta de Ingressos!" << endl;
    // int input;
    // do
    // {
    //     cout << "Selecione uma opção:" << endl;
    //     cout << "1) Entrar" << endl;
    //     cout << "2) Cadastrar" << endl;
    //     cout << "3) Fechar" << endl;
    //     cin >> input;
    //     if (input != 1 && input != 2 && input != 3)
    //     {
    //         cout << "Por favor, selecione uma opção válida!" << endl;
    //     }

    // } while (input != 1 && input != 2 && input != 3);

    // AutenticacaoRepository *autenticacaoRepository = new AutenticacaoRepository(input);
}

void Menu::gerenciarInterfaces()
{
    UsuarioInterface *usuarioInterface(NULL);
    JogoInterface *jogoInterface(NULL);
    PartidaInterface *partidaInterface(NULL);
    // IngressoRepository *ingressoRepository(NULL);
    CartaoInterface *cartaoInterface(NULL);
    int input = -1;
    do
    {
        cout << "Escolha um Domínio para gerenciar: " << endl
             << "1) Usuário" << endl
             << "2) Cartao" << endl
             << "3) Ingresso" << endl
             << "4) Partida" << endl
             << "5) Jogo" << endl
             << "6) Sair"
             << endl;
        cin >> input;
        if (input < 1 || input > 5)
        {
            cout << "Digite uma opção válida!" << endl;
        }
    } while (input < 1 || input > 5);
    switch (input)
    {
    case 1:
        usuarioInterface = new UsuarioInterface(this->db);
        break;
    case 2:
        cartaoInterface = new CartaoInterface(this->db);
        break;
    // case 3:
    //     ingressoRepository = new IngressoRepository(this->db);
    //     break;
    case 4:
        partidaInterface = new PartidaInterface(this->db);
        break;
    case 5:
        jogoInterface = new JogoInterface(this->db);
        break;
    default:
        break;
    }
}
