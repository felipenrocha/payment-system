#ifndef __USUARIO_REPOSITORY__
#define __USUARIO_REPOSITORY__
#include "repository.hpp"
#include "usuario.hpp"

class UsuarioRepository : public Repository
{
private:
    void remove();
    void update();
    void add();
    void get();
    bool createTable();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    string getCPFtoRemove();
    int getFieldToUpdate();
    string getCPFtoUpdate();

public:
    Usuario *getUsuario();
    void removerUsuario();
    void editarUsuario();
    void gerenciar();
    UsuarioRepository(sqlite3 *db);
    ~UsuarioRepository();
};

#endif