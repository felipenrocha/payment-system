#ifndef __CARTAO_HPP__
#define __CARTAO_HPP__
#include <iostream>
#include <string>
#include <ctype.h>
#include <list>
using namespace std;

class Cartao
{
private:
    string numero;
    string codigo;
    string dataValidade;

protected:
    bool checaAlgoritmoLuhn(string number);

public:
    Cartao(string number, string code, string date);
    int numeroValido(string number);
    int codigoValido(string code);
    int dataValida(string date);
    string getNumero() { return this->numero; }
    string getCodigo() { return this->codigo; }
    string getData() { return this->dataValidade; }
};

#endif