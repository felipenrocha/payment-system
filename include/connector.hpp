#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__
#include <iostream>
#include <sqlite3.h>

using namespace std;
class Connector
{
private:
    sqlite3 *db;

public:
    sqlite3 *getDB() { return this->db; }
    Connector();
    ~Connector();
};

#endif