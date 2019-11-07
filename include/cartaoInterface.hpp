#ifndef __CARTAO_INTERFACE_HPP__
#define __CARTAO_INTERFACE_HPP__
#include "interface.hpp"
#include "apresentacaoCartao.hpp"
#include "cartaoRepository.hpp"
#include "cartao.hpp"
#include "gerenciarInterface.hpp"

class CartaoInterface : public Interface
{
private:
    sqlite3 *db;

public:
    Cartao *getCartao();
    void gerenciar();
    CartaoInterface(sqlite3 *db);
protected:
    sqlite3 *getDB() { return this->db; }
};

#endif