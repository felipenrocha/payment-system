#ifndef __PARTIDA_INTERFACE__
#define __PARTIDA_INTERFACE__
#include "interface.hpp"
#include "partida.hpp"

class PartidaInterface : public Interface
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
    PartidaInterface(sqlite3 *db);
    ~PartidaInterface();
};

#endif