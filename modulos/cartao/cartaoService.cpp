#include "../../include/cartaoRepository.hpp"
#include "../../include/gerenciarInterface.hpp"
#include "../../include/apresentacaoCartao.hpp"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

CartaoRepository::CartaoRepository(sqlite3 *db) : Repository(db)
{
    bool tableCreation = this->createTable();
    if (!tableCreation)
    {
        cout << ("Tabela não foi criada.");
    }
}

CartaoRepository::~CartaoRepository()
{
}

bool CartaoRepository::createTable()
{

    char *zErrMsg = 0;
    char const *sqlQuery = "\
    CREATE TABLE CARTAO( \
    ID INT PRIMARY KEY NOT NULL, \
    NUMERO TEXT NOT NULL,\
    CODIGO TEXT NOT NULL,\
    DATA TEXT NOT NULL);";
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
void CartaoRepository::add()
{
    Cartao *newCard(NULL);
    stringstream query;
    do
    {
        Cartao *newCard = this->getCartao();

        {

            query << "INSERT INTO CARTAO (ID,NUMERO, CODIGO, DATA) VALUES("
                  << newCard->getInstancia() << ","
                  << newCard->getNumero() << ","
                  << newCard->getCodigo() << ","
                  << "'" << newCard->getData() << "')";
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
                    cout << "Cartao criado com sucesso!" << endl;
                }
                else
                {
                    cout << ("Não foi possivel cadastrar o cartao") << endl;
                }
            }
        }

    }

    while (newCard->getInstancia() != NULL);
}
Cartao *CartaoRepository::getCartao()
{

    Cartao *novoCartao(NULL);
    string numero;
    string codigo;
    string dataValidade;
    while (!novoCartao)
    {
        cout << "Digite o Numero do Cartao: ";
        cin >> numero;
        cout << "Digite o Código do Cartão: ";
        cin >> codigo;
        cout << "Digite a data de Validade do novo cartão: ";
        cin >> dataValidade;

        try
        {
            novoCartao = new Cartao(numero, codigo, dataValidade);
        }
        catch (invalid_argument e)
        {
            cout << e.what() << endl;
        }
    }
    return novoCartao;
}
void CartaoRepository::get()
{
    char const *sqlQuery = "select * from CARTAO";
    char *zErrMsg = 0;
    const char *data = "Callback function called";
    int result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    if (result != SQLITE_OK)
    {
        cout << "SQL error:" << zErrMsg << endl;
        ;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Operação bem sucedida." << endl;
    }
}
void CartaoRepository::remove()
{

    ApresentacaoCartao *apresentacaoCartao = new ApresentacaoCartao();
    string id = apresentacaoCartao->getIdtoRemove();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;
    query << "DELETE FROM CARTAO WHERE ID='" << id << "';";
    const char *data = "Callback function called";
    string s = query.str();
    char const *sqlQuery = &s[0];
    result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);

    if (result != SQLITE_OK)
    {
        cout << "Cartao não encontrado."
             << "SQLError: " << zErrMsg << endl;
    }
    else
    {
        cout << "Cartao Removido com sucesso!" << endl;
    }
}
void CartaoRepository::update()
{
    ApresentacaoCartao *apresentacaoCartao = new ApresentacaoCartao();
    string id = apresentacaoCartao->getIdtoUpdate();
    int option = apresentacaoCartao->getFieldToUpdate();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;
    // Cartao cartao2("3223876379348459", "123", "10/22");

    if (option == 1)
    {
        string newNumber;
        Cartao *cartaoBase(NULL);
        do
        {
            cout << "Insira o novo Número: ";
            cin >> newNumber;
            try
            {
                cartaoBase = new Cartao(newNumber, "123", "10/22");
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!cartaoBase);

        query << "UPDATE CARTAO SET NUMERO ='" << newNumber << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 2)
    {
        string newCode;
        Cartao *cartaoBase(NULL);
        do
        {
            cout << "Insira o novo Código: ";
            cin >> newCode;
            try
            {
                cartaoBase = new Cartao("3223876379348459", newCode, "10/22");
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!cartaoBase);

        query << "UPDATE CARTAO SET CODIGO ='" << newCode << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else if (option == 3)
    {
        string newDate;
        Cartao *cartaoBase(NULL);
        do
        {
            cout << "Insira a nova Data de validade: ";
            cin >> newDate;
            try
            {
                cartaoBase = new Cartao("3223876379348459", "123", newDate);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!cartaoBase);

        query << "UPDATE CARTAO SET DATA ='" << newDate << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
}

int CartaoRepository::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}