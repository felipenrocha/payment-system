#ifndef __USUARIO_INTERFACE__
#define __USUARIO_INTERFACE__
#include "interface.hpp"
#include "usuario.hpp"

class UsuarioInterface : public Interface
{
private:
    Usuario *user;
    ~UsuarioInterface();
    void create(Singleton *instancia);
    void remove(Singleton *instancia);
    void update(Singleton *instancia);

public:
    UsuarioInterface(Usuario *padrao, Interface *object);
    bool registrarUsuario();
    bool loginUsuario();
    bool removerUsuario();
    bool editarUsuario();
};

#endif