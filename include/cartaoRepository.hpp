#ifndef __CARTAO_REPOSITORY__
#define __CARTAO_REPOSITORY__
#include "repository.hpp"
#include "cartao.hpp"

class CartaoRepository : public Repository
{
private:
    void remove();
    void update();
    void add();
    void get();
    bool createTable();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    string getIDtoRemove();
    int getFieldToUpdate();
    string getIDtoUpdate();
    // void printStates();
    // void printTipos();

public:
    Cartao *getCartao();
    void removerCartao();
    void editarCartao();
    void gerenciar();
    CartaoRepository(sqlite3 *db);
    ~CartaoRepository();
};

#endif