#if !defined(JOGO_HPP_INCLUDED)
#define JOGO_HPP_INCLUDED
#include <iostream>
#include <string>
#include <ctype.h>
#include <list>
#include "singleton.hpp"
using namespace std;
/**
* Classe responsável por conter o domínio Jogo
*/

class Jogo : public Singleton
{
private:
    /**
* Entidades: 
*/
    Singleton *id;
    string codigoDoJogo;
    string nomeDoJogo;
    string cidade;
    string estado;
    int tipoDoJogo;

public:
    Jogo() : Singleton()
    {
        this->id = NULL;
        this->instancia = 0;
    }
    Jogo(string code, string name, string city, string state, int type);
    string getCodigo() { return this->codigoDoJogo; }
    string getNome() { return this->nomeDoJogo; }
    string getCidade() { return this->cidade; }
    string getEstado() { return this->estado; }
    int getTipo() { return this->tipoDoJogo; }
    string getTipoDoJogo();
    int codigoValido(string code);
    int nomeECidadeValido(string name);
    int estadoValido(string state);
    int tipoValido(int type);
};

#endif // JOGO_HPP_INCLUDED
