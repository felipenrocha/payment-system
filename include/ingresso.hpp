#ifndef __INGRESSO_HPP__
#define __INGRESSO_HPP__
#include <iostream>
#include <string>
#include <ctype.h>
#include "singleton.hpp"
#include <list>
using namespace std;

/**
* Classe responsável por conter o domínio Ingresso
*/
class Ingresso : public Singleton
{
private:
    /**
* Entidades: 
*/
    Singleton *id;
    string codigo;

public:
    Ingresso() : Singleton()
    {
        this->id = NULL;
        this->instancia = 0;
    }
    Ingresso(string code);
    int codigoValido(string code);
    string getCodigo() { return this->codigo; }
};

#endif