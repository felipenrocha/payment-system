#ifndef __PARTIDA_INTERFACE_HPP__
#define __PARTIDA_INTERFACE_HPP__
#include "interface.hpp"
#include "apresentacaoPartida.hpp"
#include "partidaRepository.hpp"
#include "partida.hpp"
#include "gerenciarInterface.hpp"

class PartidaInterface : public Interface
{
private:
    sqlite3 *db;

public:
    Partida *getPartida();
    void gerenciar();
    PartidaInterface(sqlite3 *db);
    
protected:
    sqlite3 *getDB() { return this->db; }
};

#endif