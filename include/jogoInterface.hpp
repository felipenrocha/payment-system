#ifndef __JOGO_INTERFACE_HPP__
#define __JOGO_INTERFACE_HPP__
#include "interface.hpp"
#include "apresentacaoJogo.hpp"
#include "jogoRepository.hpp"
#include "jogo.hpp"
#include "gerenciarInterface.hpp"

class JogoInterface : public Interface
{
private:
    sqlite3 *db;

public:
    Jogo *getJogo();
    void gerenciar();
    JogoInterface(sqlite3 *db);
    
protected:
    sqlite3 *getDB() { return this->db; }
};

#endif