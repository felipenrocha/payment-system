#ifndef __REPOSITORY__
#define __REPOSITORY__
#include <iostream>
#include <string>
#include <sqlite3.h>
using namespace std;

class Repository
{
public:
    virtual void get() = 0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    virtual bool createTable() = 0;
    Repository(sqlite3 *database)
    {
        this->db = database;
    };

protected:
    sqlite3 *getDB() { return this->db; }

private:
    sqlite3 *db;
};

#endif