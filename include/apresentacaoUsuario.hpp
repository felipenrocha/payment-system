#ifndef __APRESENTACAO_USUARIO_HPP__
#define __APRESENTACAO_USUARIO_HPP__
#include "apresentacao.hpp"

class ApresentacaoUsuario : public Apresentacao
{
public:
    string getIdtoRemove();
    string getIdtoUpdate();
    int getFieldToUpdate();
};

#endif