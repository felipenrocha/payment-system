#include "../../include/jogoInterface.hpp"
#include "../../include/gerenciarInterface.hpp"
#include <iostream>
// #include <string.h>
#include <string>
#include <sstream>
static list<string> estados = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE",

                               "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
;
using namespace std;

JogoInterface::JogoInterface(sqlite3 *db) : Interface(db)
{
    bool tableCreation = this->createTable();
    if (tableCreation)
    {
        // cout << "Tabela Criada com sucesso!" << endl;
        this->gerenciar();
    }
    else
    {
        cout << ("Tabela não foi criada");
    }
}

JogoInterface::~JogoInterface()
{
}

bool JogoInterface::createTable()
{

    char *zErrMsg = 0;
    char const *sqlQuery = "CREATE TABLE JOGO"
                           "(              "
                           "ID INT PRIMARY KEY NOT NULL,"
                           "CODIGO TEXT NOT NULL,"
                           "NOME TEXT NOT NULL,"
                           "CIDADE TEXT NOT NULL,"
                           "ESTADO TEXT NOT NULL,"
                           "TIPO INT NOT NULL);";
    int query = sqlite3_exec(this->getDB(), sqlQuery, callback, 0, &zErrMsg);
    if (!query)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void JogoInterface::add()
{
    Jogo *newGame = this->getJogo();
    stringstream query;
    query << "INSERT INTO JOGO (ID,CODIGO,NOME, CIDADE, ESTADO, TIPO) VALUES("
          << newGame->getInstancia() << ","
          << "'" << newGame->getCodigo() << "',"
          << "'" << newGame->getNome() << "',"
          << "'" << newGame->getCidade() << "',"
          << "'" << newGame->getEstado() << "',"
          << "'" << newGame->getTipo() << "')";
    string s = query.str();
    char *str = &s[0];

    sqlite3_stmt *statement;
    int result;

    char *command = str;
    {
        if (sqlite3_prepare(this->getDB(), command, -1, &statement, 0) == SQLITE_OK)
        {
            int res = sqlite3_step(statement);
            result = res;
            sqlite3_finalize(statement);
            cout << "Jogo criado com sucesso!" << endl;
        }
        else
        {
            cout << ("Não foi possivel cadastrar o Jogo") << endl;
        }
    }
}
Jogo *JogoInterface::getJogo()
{
    Jogo *novoJogo = new Jogo();
    do
    {
        string codigoJogo;
        string nomeJogo;
        string estado;
        string cidade;
        int tipo;

        cout << "Digite o Codigo do Jogo: ";
        cin >> codigoJogo;
        cout << "Digite o Nome do Jogo: ";
        cin.ignore();
        getline(std::cin, nomeJogo);
        cout << "Digite o Estado do Jogo: " << endl;
        this->printStates();
        cin >> estado;
        cout << "Digite o nome da Cidade do Jogo: ";
        cin.ignore();
        getline(cin, cidade);
        cout << "Digite o tipo do Jogo: " << endl;
        this->printTipos();
        cin >> tipo;
        try
        {
            novoJogo = new Jogo(codigoJogo, nomeJogo, cidade, estado, tipo);
        }
        catch (invalid_argument e)
        {
            cout << e.what() << endl;
        }

    } while (novoJogo->getInstancia() == NULL);

    return novoJogo;
}
void JogoInterface::get()
{
    char const *sqlQuery = "select * from JOGO";
    char *zErrMsg = 0;
    const char *data = "Callback function called";
    int result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    if (result != SQLITE_OK)
    {
        cout << "SQL error:" << zErrMsg << endl;
        ;
        sqlite3_free(zErrMsg);
    }
}
void JogoInterface::remove()
{
    string codigo = getCodigotoRemove();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;
    query << "DELETE FROM JOGO WHERE CODIGO='" << codigo << "';";
    const char *data = "Callback function called";
    string s = query.str();
    char const *sqlQuery = &s[0];
    result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);

    if (result != SQLITE_OK)
    {
        cout << "Jogo não encontrado."
             << "SQLError: " << zErrMsg << endl;
    }
    else
    {
        cout << "Jogo Removido com sucesso!" << endl;
    }
}
void JogoInterface::update()
{
    string codigo = getCodigotoUpdate();
    int option = getFieldToUpdate();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;

    if (option == 1)
    {
        string newCode;
        Jogo *jogoBase(NULL);
        do
        {
            cout << "Insira o novo codigo: ";
            cin >> newCode;
            try
            {
                jogoBase = new Jogo(newCode, "AAAAAA", "Brasilia", "AM", 1);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!jogoBase);

        query << "UPDATE JOGO SET CODIGO ='" << newCode << "'WHERE CODIGO = '" << codigo << "'";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 2)
    {
        string newNome;
        Jogo *jogoBase(NULL);
        do
        {
            cout << "Insira o novo Nome: ";
            cin.ignore();
            getline(cin, newNome);
            try
            {
                jogoBase = new Jogo("123", newNome, "Brasilia", "AM", 1);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!jogoBase);

        query << "UPDATE JOGO SET NOME ='" << newNome << "'WHERE CODIGO = '" << codigo << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 3)
    {
        string newCity;
        Jogo *jogoBase(NULL);
        do
        {
            cout << "Insira o nome da nova Cidade: ";
            cin.ignore();
            getline(cin, newCity);
            try
            {
                jogoBase = new Jogo("123", "AAAAAA", newCity, "AM", 1);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!jogoBase);

        query << "UPDATE JOGO SET CIDADE ='" << newCity << "'WHERE CODIGO = '" << codigo << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 4)
    {
        string newState;
        Jogo *jogoBase(NULL);
        do
        {
            cout << "Insira a sigla do novo estado: ";
            this->printStates();

            cin >> newState;
            try
            {
                jogoBase = new Jogo("123", "AAAAAA", "Brasilia", newState, 1);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!jogoBase);

        query << "UPDATE JOGO SET ESTADO ='" << newState << "'WHERE CODIGO = '" << codigo << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 4)
    {
        string newState;
        Jogo *jogoBase(NULL);
        do
        {
            cout << "Insira a sigla do novo estado: ";
            this->printStates();

            cin >> newState;
            try
            {
                jogoBase = new Jogo("123", "AAAAAA", "Brasilia", newState, 1);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!jogoBase);

        query << "UPDATE JOGO SET ESTADO ='" << newState << "'WHERE CODIGO = '" << codigo << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 5)
    {
        int newType;
        Jogo *jogoBase(NULL);
        do
        {
            cout << "Insira o novo tipo: ";
            this->printTipos();

            cin >> newType;
            try
            {
                jogoBase = new Jogo("123", "AAAAAA", "Brasilia", "AM", newType);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!jogoBase);

        query << "UPDATE JOGO SET TIPO ='" << newType << "'WHERE CODIGO = '" << codigo << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
}
void JogoInterface::gerenciar()
{
    int operacao;
    do
    {
        operacao = printMenuGerenciar("Jogo");
        switch (operacao)
        {
        case 1:
            this->get();
            break;
        case 2:
            this->add();
            break;
        case 3:
            this->remove();
            break;
        case 4:
            this->update();
            break;
        default:
            break;
        }
    } while (operacao >= 1 && operacao <= 4);
}

int JogoInterface::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

string JogoInterface::getCodigotoRemove()
{
    string codigo;
    cout << "Digite o Codigo do Jogo a ser removido: ";
    cin >> codigo;

    return codigo;
}

string JogoInterface::getCodigotoUpdate()
{
    string codigo;
    cout << "Digite o Codigo do Jogo a ser editado: ";
    cin >> codigo;

    return codigo;
}

int JogoInterface::getFieldToUpdate()
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

    } while (operacao <= 1 || operacao >= 6);
}

void JogoInterface::printStates()
{
    for (auto const &i : estados)
    {
        cout << i << " ";
    }
    cout << endl;
}
void JogoInterface::printTipos()
{
    cout << "1) Local" << endl
         << "2) Estadual" << endl
         << "3) Nacional" << endl
         << "4) Internacional" << endl;
}