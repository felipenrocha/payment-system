#ifndef __APRESENTACAO_JOGO_HPP__
#define __APRESENTACAO_JOGO_HPP__
#include "apresentacao.hpp"
#include <list>

static list<string> estados = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE",

                               "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
;
class ApresentacaoJogo : public Apresentacao
{
public:
    string getIdtoRemove();
    string getIdtoUpdate();
    int getFieldToUpdate();
    void printStates();
    void printTipos();
};

#endif