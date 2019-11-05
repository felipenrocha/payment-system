#ifndef __JOGO_REPOSITORY__
#define __JOGO_REPOSITORY__
#include "repository.hpp"
#include "jogo.hpp"

class JogoRepository : public Repository
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
    JogoRepository(sqlite3 *db);
    ~JogoRepository();
};

#endif