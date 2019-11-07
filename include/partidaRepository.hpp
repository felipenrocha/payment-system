#ifndef __PARTIDA_REPOSITORY__
#define __PARTIDA_REPOSITORY__
#include "repository.hpp"
#include "partida.hpp"

class PartidaRepository : public Repository
{
public:
    void remove();
    void update();
    void add();
    void get();
    bool createTable();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    Partida *getPartida();
    PartidaRepository(sqlite3 *db);
    ~PartidaRepository();
};

#endif