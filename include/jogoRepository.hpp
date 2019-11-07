#ifndef __JOGO_REPOSITORY__
#define __JOGO_REPOSITORY__
#include "repository.hpp"
#include "jogo.hpp"

class JogoRepository : public Repository
{
public:
    void remove();
    void update();
    void add();
    void get();
    bool createTable();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    Jogo *getJogo();
    JogoRepository(sqlite3 *db);
    ~JogoRepository();
};

#endif