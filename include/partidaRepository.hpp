#ifndef __PARTIDA_REPOSITORY__
#define __PARTIDA_REPOSITORY__
#include "repository.hpp"
#include "partida.hpp"

class PartidaRepository : public Repository
{
private:
    void remove();
    void update();
    void add();
    void get();
    bool createTable();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    string getNumerotoRemove();
    int getFieldToUpdate();
    string getNumerotoUpdate();

public:
    Partida *getPartida();
    void removerPartida();
    void editarPartida();
    void gerenciar();
    PartidaRepository(sqlite3 *db);
    ~PartidaRepository();
};

#endif