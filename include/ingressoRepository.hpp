#ifndef __INGRESSO_REPOSITORY__
#define __INGRESSO_REPOSITORY__
#include "repository.hpp"
#include "ingresso.hpp"

class IngressoRepository : public Repository
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
    IngressoRepository(sqlite3 *db);
    ~IngressoRepository();
};

#endif