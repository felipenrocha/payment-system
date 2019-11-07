#ifndef __CARTAO_REPOSITORY__
#define __CARTAO_REPOSITORY__
#include "repository.hpp"
#include "cartao.hpp"

class CartaoRepository : public Repository
{
public:
    void remove();
    void update();
    void add();
    void get();
    bool createTable();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    Cartao *getCartao();
    CartaoRepository(sqlite3 *db);
    ~CartaoRepository();
};

#endif