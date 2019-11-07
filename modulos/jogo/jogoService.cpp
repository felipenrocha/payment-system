#include "../../include/jogoRepository.hpp"
#include "../../include/gerenciarInterface.hpp"
#include "../../include/jogoInterface.hpp"
#include <iostream>

#include <string>
#include <sstream>

using namespace std;

JogoRepository::JogoRepository(sqlite3 *db) : Repository(db)
{
    bool tableCreation = this->createTable();
    if (!tableCreation)
    {
        throw invalid_argument("Tabela não foi criada");
    }
}

JogoRepository::~JogoRepository()
{
}

bool JogoRepository::createTable()
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
void JogoRepository::add()
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
Jogo *JogoRepository::getJogo()
{
    ApresentacaoJogo *apresentacaoJogo = new ApresentacaoJogo();
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
        apresentacaoJogo->printStates();
        cin >> estado;
        cout << "Digite o nome da Cidade do Jogo: ";
        cin.ignore();
        getline(cin, cidade);
        cout << "Digite o tipo do Jogo: " << endl;
        apresentacaoJogo->printTipos();
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
void JogoRepository::get()
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
void JogoRepository::remove()
{
    ApresentacaoJogo *apresentacaoJogo = new ApresentacaoJogo();
    string id = apresentacaoJogo->getIdtoRemove();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;
    query << "DELETE FROM JOGO WHERE ID='" << id << "';";
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
void JogoRepository::update()
{
    ApresentacaoJogo *apresentacaoJogo = new ApresentacaoJogo();
    string id = apresentacaoJogo->getIdtoUpdate();
    int option = apresentacaoJogo->getFieldToUpdate();
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

        query << "UPDATE JOGO SET CODIGO ='" << newCode << "'WHERE ID = '" << id << "'";
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

        query << "UPDATE JOGO SET NOME ='" << newNome << "'WHERE ID = '" << id << "';";
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

        query << "UPDATE JOGO SET CIDADE ='" << newCity << "'WHERE ID = '" << id << "';";
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
            apresentacaoJogo->printStates();

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

        query << "UPDATE JOGO SET ESTADO ='" << newState << "'WHERE ID = '" << id << "';";
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
            apresentacaoJogo->printStates();

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

        query << "UPDATE JOGO SET ESTADO ='" << newState << "'WHERE ID = '" << id << "';";
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
            apresentacaoJogo->printTipos();

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

        query << "UPDATE JOGO SET TIPO ='" << newType << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
}


int JogoRepository::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
