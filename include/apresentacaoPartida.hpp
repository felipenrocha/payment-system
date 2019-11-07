#ifndef __APRESENTACAO_PARTIDA_HPP__
#define __APRESENTACAO_PARTIDA_HPP__
#include "apresentacao.hpp"
;
class ApresentacaoPartida : public Apresentacao
{
public:
    string getIdtoRemove();
    string getIdtoUpdate();
    int getFieldToUpdate();

};

#endif