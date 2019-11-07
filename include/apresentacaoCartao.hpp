#ifndef __APRESENTACAO_CARTAO_HPP__
#define __APRESENTACAO_CARTAO_HPP__
#include "apresentacao.hpp"

class ApresentacaoCartao : public Apresentacao
{
public:
    string getIdtoRemove();
    string getIdtoUpdate();
    int getFieldToUpdate();
};

#endif