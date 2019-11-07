#ifndef __USUARIO_REPOSITORY__
#define __USUARIO_REPOSITORY__
#include "repository.hpp"
#include "usuario.hpp"

class UsuarioRepository : public Repository
{
public:
    UsuarioRepository(sqlite3 *db);
    ~UsuarioRepository();
    void remove();
    void update();
    void add();
    void get();
    bool createTable();
    Usuario *getUsuario();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
};

#endif