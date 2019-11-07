#include "../../include/partidaInterface.hpp"
#include "../../include/gerenciarInterface.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

PartidaRepository::PartidaRepository(sqlite3 *db) : Repository(db)
{
    bool tableCreation = this->createTable();
    if (tableCreation)
    {
        // cout << "Tabela Criada com sucesso!" << endl;
        // this->gerenciar();
    }
    else
    {
        cout << ("Tabela não foi criada") << endl;
    }
}

PartidaRepository::~PartidaRepository()
{
}

bool PartidaRepository::createTable()
{

    char *zErrMsg = 0;
    char const *sqlQuery = "CREATE TABLE PARTIDA"
                           "(              "
                           "ID INT PRIMARY KEY NOT NULL,"
                           "NUMERO INT NOT NULL,"
                           "DATA TEXT NOT NULL,"
                           "HORARIO TEXT NOT NULL,"
                           "PRECO REAL NOT NULL,"
                           "DISPONIBILIDADE INT NOT NULL);";
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
void PartidaRepository::add()
{
    Partida *newGame = this->getPartida();
    stringstream query;
    query << "INSERT INTO PARTIDA (ID, NUMERO, DATA, HORARIO, PRECO, DISPONIBILIDADE) VALUES("
          << newGame->getId() << ","
          << "'" << newGame->getNumeroSala() << "',"
          << "'" << newGame->getData() << "',"
          << "'" << newGame->getHorario() << "',"
          << "'" << newGame->getPreco() << "',"
          << "'" << newGame->getDisponibilidade() << "')";
    string s = query.str();
    char *str = &s[0];

    sqlite3_stmt *timement;
    int result;

    char *command = str;
    {
        if (sqlite3_prepare(this->getDB(), command, -1, &timement, 0) == SQLITE_OK)
        {
            int res = sqlite3_step(timement);
            result = res;
            sqlite3_finalize(timement);
            cout << "Partida criado com sucesso!" << endl;
        }
        else
        {
            cout << ("Não foi possivel cadastrar o Partida") << endl;
        }
    }
}
Partida *PartidaRepository::getPartida()
{
    Partida *novoPartida = NULL;
    do
    {
        int numeroPartida;
        string dataPartida;
        string horario;
        double preco;
        int disponibilidade;

        cout << "Digite o Numero da Sala: ";
        cin >> numeroPartida;
        cout << "Digite o Data da Sala: ";
        cin.ignore();
        getline(std::cin, dataPartida);
        cout << "Digite o horario da Sala: " << endl;
        cin >> horario;
        cout << "Digite o Preço da Sala: ";
        cin >> preco;
        cout << "Digite a disponibilidade da Sala: " << endl;
        cin >> disponibilidade;
        try
        {
            novoPartida = new Partida(numeroPartida, dataPartida, horario, preco, disponibilidade);
        }
        catch (invalid_argument e)
        {
            cout << e.what() << endl;
        }

    } while (novoPartida == NULL);

    return novoPartida;
}
void PartidaRepository::get()
{
    char const *sqlQuery = "select * from PARTIDA";
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
void PartidaRepository::remove()
{

    ApresentacaoPartida *apresentacaoPartida = new ApresentacaoPartida();

    string id = apresentacaoPartida->getIdtoRemove();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;
    query << "DELETE FROM PARTIDA WHERE ID='" << id << "';";
    const char *data = "Callback function called";
    string s = query.str();
    char const *sqlQuery = &s[0];
    result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);

    if (result != SQLITE_OK)
    {
        cout << "Partida não encontrado."
             << "SQLError: " << zErrMsg << endl;
    }
    else
    {
        cout << "Partida Removido com sucesso!" << endl;
    }
}
void PartidaRepository::update()
{
    ApresentacaoPartida *apresentacaoPartida = new ApresentacaoPartida();

    string id = apresentacaoPartida->getIdtoUpdate();
    int option = apresentacaoPartida->getFieldToUpdate();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;

    if (option == 1)
    {
        int newNumber;
        Partida *partidaBase(NULL);
        do
        {
            cout << "Insira o novo numero: ";
            cin >> newNumber;
            try
            {
                partidaBase = new Partida(newNumber, "22/11/98", "17:45", 150.00, 250);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!partidaBase);

        query << "UPDATE PARTIDA SET NUMERO ='" << newNumber << "'WHERE ID = '" << id << "'";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 2)
    {
        string newData;
        Partida *partidaBase(NULL);
        do
        {
            cout << "Insira a novo Data: ";
            cin.ignore();
            getline(cin, newData);
            try
            {
                partidaBase = new Partida(1, newData, "15:45", 150.00, 50);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!partidaBase);

        query << "UPDATE PARTIDA SET DATA ='" << newData << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 3)
    {
        double newPrice;
        Partida *partidaBase(NULL);
        do
        {
            cout << "Insira o novo Preço: ";
            cin >> newPrice;
            try
            {
                partidaBase = new Partida(1, "22/11/15", "15:45", newPrice, 50);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!partidaBase);

        query << "UPDATE PARTIDA SET PRECO ='" << newPrice << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 4)
    {
        string newTime;
        Partida *partidaBase(NULL);
        do
        {
            cout << "Insira o novo horario: ";
            cin >> newTime;
            try
            {
                partidaBase = new Partida(1, "22/11/98", newTime, 150.00, 50);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!partidaBase);

        query << "UPDATE PARTIDA SET HORARIO ='" << newTime << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 5)
    {
        int newDisponibility;
        Partida *partidaBase(NULL);
        do
        {
            cout << "Insira o novo disponibilidade: ";
            cin >> newDisponibility;
            try
            {
                partidaBase = new Partida(1, "22/11/98", "15:45", 150, newDisponibility);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!partidaBase);

        query << "UPDATE PARTIDA SET DISPONIBILIDADE ='" << newDisponibility << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
}

int PartidaRepository::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
