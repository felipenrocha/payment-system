#ifndef __CARTAO_INTERFACE__
#define __CARTAO_INTERFACE__
#include "interface.hpp"
#include "cartao.hpp"

class CartaoInterface : public Interface
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
    CartaoInterface(sqlite3 *db);
    ~CartaoInterface();
};

#endif