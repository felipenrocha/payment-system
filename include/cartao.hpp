#ifndef __CARTAO_HPP__
#define __CARTAO_HPP__
#include <iostream>
#include <string>
#include <ctype.h>
#include <list>
#include "singleton.hpp"
using namespace std;
/**
* Classe responsável por conter o domínio Cartao
*/

class Cartao : public Singleton
{
private:
    /**
* Entidades: 
*/
    Singleton *id;
    string numero;
    string codigo;
    string dataValidade;

protected:
    bool checaAlgoritmoLuhn(string number);

public:
    Cartao() : Singleton()
    {
        this->id = NULL;
        this->instancia = NULL;
    }
    Cartao(string number, string code, string date);
    int numeroValido(string number);
    int codigoValido(string code);
    int dataValida(string date);
    string getNumero() { return this->numero; }
    string getCodigo() { return this->codigo; }
    string getData() { return this->dataValidade; }
};

#endif