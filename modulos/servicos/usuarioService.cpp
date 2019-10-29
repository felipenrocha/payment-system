#include "../../include/usuarioInterface.hpp"
#include "../../include/gerenciarInterface.hpp"
#include <mysqlx/xdevapi.h>
UsuarioInterface::UsuarioInterface(sqlite3 *db) : Interface(db)
{
    bool tableCreation = this->createTable();
    if (tableCreation)
    {
        this->gerenciar();
    }
    else
    {
        throw invalid_argument("Tabela não foi criada");
    }
}

UsuarioInterface::~UsuarioInterface()
{
}

bool UsuarioInterface::createTable()
{
    const char *sqlQuery;

    sqlQuery = "CREATE IF NOT EXISTS TABLE USUARIO("
               "ID INT PRIMARY        KEY      NOT NULL,"
               "CPF                   TEXT     NOT NULL,"
               "SENHA                 TEXT     NOT NULL,"
               ");";
    int query = sqlite3_exec(this->getDB(), sqlQuery, NULL, NULL, NULL);

    if (!query)
    {
        throw invalid_argument("Não foi possível criar a tabela");
    }
    else
    {
        return true;
    }
}
void UsuarioInterface::add()
{
}
void UsuarioInterface::create()
{
}
void UsuarioInterface::remove()
{
}
void UsuarioInterface::update()
{
}
void UsuarioInterface::gerenciar()
{
    int operacao = printMenuGerenciar("Usuario");
    switch (operacao)
    {
    case 1:
        this->get();
        break;
    case 2:
        this->create();
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
}