#ifndef __INGRESSO_HPP__
#define __INGRESSO_HPP__
#include <iostream>
#include <string>
#include <ctype.h>
#include <list>
using namespace std;

class Ingresso
{
private:
    string codigo;

public:
    Ingresso(string code);
    int codigoValido(string code);
    string getCodigo() { return this->codigo; }
};

#endif