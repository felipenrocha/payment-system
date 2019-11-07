#include <iostream>
#include "./include/menu.hpp"
#include <sqlite3.h>

int main(int argc, const char **argv)
{
    // Pointer to SQLite connection
    sqlite3 *db;
    // Save the connection result
    int exit = 0;
    exit = sqlite3_open("sqlite3/SGVI_API", &db);

    // Test if there was an error
    if (exit)
    {

        cout << "DB Open Error: " << sqlite3_errmsg(db) << endl;
    }
    else
    {
        Menu menu(db);

        // cout << "Opened Database Successfully!" << endl;
    }

    return 0;
}