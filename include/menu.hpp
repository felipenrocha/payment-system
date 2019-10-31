#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include <string>
#include <ctype.h>
#include "index.hpp"

// TODO: FIX BUG usuarioInterface-> não esta sendo referenciada como tipo.
using namespace std;

class Menu
{
public:
    sqlite3 *db;
    Menu(sqlite3 * db);
    void login();
    void registrar();
    // ~Menu();
    void telaInicial();
    void gerenciarInterfaces();
};

#endif