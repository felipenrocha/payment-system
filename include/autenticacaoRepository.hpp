
#ifndef __AUTENTICACAO_REPOSITORY_HPP__
#define __AUTENTICACAO_REPOSITORY_REPOSITORY_HPP__
#include "singleton.hpp"
#include "usuario.hpp"

class AutenticacaoRepository : public Singleton
{
private:
    ~AutenticacaoRepository();

public:
    void login();
    void registrar();
    AutenticacaoRepository(int option);
};

#endif


// #ifndef __AUTENTICACAO_HPP__
// #define __AUTENTICACAO_HPP__
// #include "repository.hpp"
// #include "usuario.hpp"

// class AutenticacaoRepository : public Repository
// {
// private:
//     void create();
//     void remove();
//     void update();
//     ~AutenticacaoRepository(){};
// protected:
//     void registrarAutenticacao();
//     void loginAutenticacao();

// public:
//     AutenticacaoRepository(int option);
// };

// #endif