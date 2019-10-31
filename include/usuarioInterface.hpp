#ifndef __USUARIO_INTERFACE__
#define __USUARIO_INTERFACE__
#include "interface.hpp"
#include "usuario.hpp"

class UsuarioInterface : public Interface
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
    UsuarioInterface(sqlite3 *db);
    ~UsuarioInterface();
};

#endif