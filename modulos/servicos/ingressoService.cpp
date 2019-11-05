#include "../../include/ingressoRepository.hpp"
#include "../../include/gerenciarRepository.hpp"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

IngressoRepository::IngressoRepository(sqlite3 *db) : Repository(db)
{
    bool tableCreation = this->createTable();
    if (tableCreation)
    {
        // cout << "Tabela Criada com sucesso!" << endl;
        this->gerenciar();
    }
    else
    {
        cout << ("Tabela não foi criada.");
    }
}

IngressoRepository::~IngressoRepository()
{
}

bool IngressoRepository::createTable()
{

    char *zErrMsg = 0;
    char const *sqlQuery = "CREATE TABLE INGRESSO(ID INT PRIMARY KEY NOT NULL, CODIGO TEXT NOT NULL);";
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
void IngressoRepository::add()
{
    Ingresso *newTicket(NULL);
    stringstream query;
    do
    {
        try
        {
            Ingresso *newTicket = this->getIngresso();
            {

                query << "INSERT INTO INGRESSO (ID,CODIGO) VALUES("
                      << newTicket->getInstancia() << ","
                      << "'" << newTicket->getCodigo() << "')";
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
                        cout << "Ingresso criado com sucesso!" << endl;
                    }
                    else
                    {
                        cout << ("Não foi possivel cadastrar o ingresso") << endl;
                    }
                }
            }
        }
        catch (invalid_argument e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    while (!newTicket);
}
Ingresso *IngressoRepository::getIngresso()
{
    Ingresso *novoIngresso = new Ingresso();
    do
    {
        string codigo;

        cout << "Digite o Código do Ingresso: ";
        cin >> codigo;
        try
        {
            novoIngresso = new Ingresso(codigo);
        }
        catch (invalid_argument e)
        {
            cout << e.what() << endl;
        }

    } while (novoIngresso->getInstancia() == NULL);

    return novoIngresso;
}
void IngressoRepository::get()
{
    char const *sqlQuery = "select * from INGRESSO";
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
        cout << "Opreação bem sucedida." << endl;
    }
}
void IngressoRepository::remove()
{
    string codigo = getCodigotoRemove();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;
    query << "DELETE FROM INGRESSO WHERE CODIGO='" << codigo << "';";
    const char *data = "Callback function called";
    string s = query.str();
    char const *sqlQuery = &s[0];
    result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);

    if (result != SQLITE_OK)
    {
        cout << "Ingresso não encontrado."
             << "SQLError: " << zErrMsg << endl;
    }
    else
    {
        cout << "Ingresso Removido com sucesso!" << endl;
    }
}
void IngressoRepository::update()
{
    string codigo = getCodigotoUpdate();
    int option = getFieldToUpdate();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;

    if (option == 1)
    {
        string newCodigo;
        Ingresso *ingressoBase(NULL);
        do
        {
            cout << "Insira o novo Código: ";
            cin >> newCodigo;
            try
            {
                ingressoBase = new Ingresso(newCodigo);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!ingressoBase);

        query << "UPDATE INGRESSO SET CODIGO ='" << newCodigo << "'WHERE CODIGO = '" << codigo << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
}
void IngressoRepository::gerenciar()
{
    int operacao;
    do
    {
        operacao = printMenuGerenciar("Ingresso");
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

int IngressoRepository::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

string IngressoRepository::getCodigotoRemove()
{
    string codigo;
    cout << "Digite o Código do Ingresso a ser removido:";
    cin >> codigo;

    return codigo;
}

string IngressoRepository::getCodigotoUpdate()
{
    string codigo;
    cout << "Digite o Código do Ingresso a ser editado:";
    cin >> codigo;

    return codigo;
}

int IngressoRepository::getFieldToUpdate()
{
    int operacao = -1;
    do
    {
        cout << "Selecione uma opção para editar: "
             << endl
             << "1) Editar Codigo " << endl;
        cin >> operacao;

    } while (operacao != 1);
}