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
    void get();
    ~UsuarioInterface();

public:
    void removerUsuario();
    void editarUsuario();
    void autenticacao();
    void gerenciar();
    UsuarioInterface();
};

#endif