#ifndef __USUARIO_INTERFACE__
#define __USUARIO_INTERFACE__
#include "interface.hpp"
#include "usuario.hpp"

class UsuarioInterface : public Interface
{
private:
    void create();
    void remove();
    void update();
    void add();
    bool createTable();
    ~UsuarioInterface();

public:
    void removerUsuario();
    void editarUsuario();
    void gerenciar();
    UsuarioInterface(sqlite3 *db);
};

#endif