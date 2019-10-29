#include "../include/connector.hpp"

using namespace std;

Connector::Connector()
{

    // Pointer to SQLite connection

    // Save the connection result
    int exit = 0;
    exit = sqlite3_open("SGVI_API", &this->db);

    // Test if there was an error
    if (exit)
    {

        cout << "DB Open Error: " << sqlite3_errmsg(db) << endl;
    }
    else
    {

        // cout << "Opened Database Successfully!" << endl;
    }
}

Connector::~Connector()
{

    sqlite3_close(this->db);
}