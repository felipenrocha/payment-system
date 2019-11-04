#ifndef __INGRESSO_INTERFACE__
#define __INGRESSO_INTERFACE__
#include "interface.hpp"
#include "ingresso.hpp"

class IngressoInterface : public Interface
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
    // void printStates();
    // void printTipos();

public:
    Ingresso *getIngresso();
    void removerIngresso();
    void editarIngresso();
    void gerenciar();
    IngressoInterface(sqlite3 *db);
    ~IngressoInterface();
};

#endif