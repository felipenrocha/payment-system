#ifndef __JOGO_INTERFACE__
#define __JOGO_INTERFACE__
#include "interface.hpp"
#include "jogo.hpp"

class JogoInterface : public Interface
{
private:
    void remove();
    void update();
    void add();
    void get();
    bool createTable();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    string getCodigotoRemove();
    int getFieldToUpdate();
    string getCodigotoUpdate();
    void printStates();
    void printTipos();

public:
    Jogo *getJogo();
    void removerJogo();
    void editarJogo();
    void gerenciar();
    JogoInterface(sqlite3 *db);
    ~JogoInterface();
};

#endif