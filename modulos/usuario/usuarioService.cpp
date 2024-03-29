#include "../../include/usuarioRepository.hpp"
#include "../../include/gerenciarInterface.hpp"
#include "../../include/usuarioInterface.hpp"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

UsuarioRepository::UsuarioRepository(sqlite3 *db) : Repository(db)
{
    bool tableCreation = this->createTable();
    if (!tableCreation)
    {
        throw invalid_argument("Tabela não foi criada");
    }
    else
    {
        // UsuarioInterface *usuarioInterface = new UsuarioInterface(this->getDB());
        // usuarioInterface->gerenciar();
    }
}

UsuarioRepository::~UsuarioRepository()
{
}

bool UsuarioRepository::createTable()
{

    char *zErrMsg = 0;
    char const *sqlQuery = "CREATE TABLE USUARIO(ID INT PRIMARY KEY     NOT NULL, CPF TEXT NOT NULL, SENHA TEXT NOT NULL);";
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
void UsuarioRepository::add()
{


    Usuario *newUser = this->getUsuario();
    stringstream query;
    query << "INSERT INTO USUARIO (ID,CPF,SENHA) VALUES("
          << newUser->getInstancia() << ","
          << "'" << newUser->getCpf() << "',"
          << "'" << newUser->getSenha() << "')";
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
            cout << "Usuário criado com sucesso!" << endl;
        }
        else
        {
            cout << ("Não foi possivel cadastrar o usuário") << endl;
        }
    }
}

void UsuarioRepository::get()
{
    char const *sqlQuery = "select * from USUARIO";
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
void UsuarioRepository::remove()
{
    ApresentacaoUsuario *apresentacaoUsuario = new ApresentacaoUsuario();
    string id = apresentacaoUsuario->getIdtoRemove();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;
    query << "DELETE FROM USUARIO WHERE ID='" << id << "';";
    const char *data = "Callback function called";
    string s = query.str();
    char const *sqlQuery = &s[0];
    result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);

    if (result != SQLITE_OK)
    {
        cout << "Usuario não encontrado."
             << "SQLError: " << zErrMsg << endl;
    }
    else
    {
        cout << "Usuário Removido com sucesso!" << endl;
    }
}
void UsuarioRepository::update()
{
    ApresentacaoUsuario *apresentacaoUsuario = new ApresentacaoUsuario();
    string id = apresentacaoUsuario->getIdtoRemove();
    int option = apresentacaoUsuario->getFieldToUpdate();
    int result = 0;
    char *zErrMsg = 0;
    stringstream query;

    if (option == 1)
    {
        string newCpf;
        Usuario *usuarioBase(NULL);
        do
        {
            cout << "Insira o novo CPF: ";
            cin >> newCpf;
            try
            {
                usuarioBase = new Usuario(newCpf, "Admin123");
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!usuarioBase);

        query << "UPDATE USUARIO SET CPF ='" << newCpf << "'WHERE ID = '" << id << "';";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
    else
    {
        string newPassword;
        Usuario *usuarioBase(NULL);
        do
        {
            cout << "Insira a nova senha: ";
            cin >> newPassword;
            try
            {
                usuarioBase = new Usuario("025.335.231-27", newPassword);
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }

        } while (!usuarioBase);

        query << "UPDATE USUARIO SET SENHA ='" << newPassword << "'WHERE ID = '" << id << "'";
        const char *data = "Callback function called";
        string s = query.str();
        char const *sqlQuery = &s[0];
        result = sqlite3_exec(this->getDB(), sqlQuery, callback, (void *)data, &zErrMsg);
    }
}

int UsuarioRepository::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
Usuario *UsuarioRepository::getUsuario()
{
    Usuario *novoUsuario = new Usuario();
    do
    {
        string cpf;
        string senha;

        cout << "Digite o CPF: ";
        cin >> cpf;
        cout << "Digite a Senha: ";
        cin >> senha;
        try
        {
            novoUsuario = new Usuario(cpf, senha);
        }
        catch (invalid_argument e)
        {
            cout << e.what() << endl;
        }

    } while (novoUsuario->getId() == NULL);

    return novoUsuario;
}