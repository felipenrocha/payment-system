#ifndef __USUARIO_INTERFACE_HPP__
#define __USUARIO_INTERFACE_HPP__
#include "interface.hpp"
#include "apresentacaoUsuario.hpp"
#include "usuarioRepository.hpp"
#include "usuario.hpp"
#include "gerenciarInterface.hpp"

class UsuarioInterface : public Interface
{
private:
    sqlite3 *db;

public:
    Usuario *getUsuario();
    void gerenciar();
    UsuarioInterface(sqlite3 *db);
protected:
    sqlite3 *getDB() { return this->db; }
};

#endif