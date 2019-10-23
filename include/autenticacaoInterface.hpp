
#ifndef __AUTENTICACAO_INTERFACE_HPP__
#define __AUTENTICACAO_INTERFACE_INTERFACE_HPP__
#include "interface.hpp"
#include "usuario.hpp"

class AutenticacaoInterface : public Interface
{
private:
    void create();
    void remove();
    void update();
    ~AutenticacaoInterface();

public:
    void login();
    void registrar();
    AutenticacaoInterface(int option);
};

#endif


// #ifndef __AUTENTICACAO_HPP__
// #define __AUTENTICACAO_HPP__
// #include "interface.hpp"
// #include "usuario.hpp"

// class AutenticacaoInterface : public Interface
// {
// private:
//     void create();
//     void remove();
//     void update();
//     ~AutenticacaoInterface(){};
// protected:
//     void registrarAutenticacao();
//     void loginAutenticacao();

// public:
//     AutenticacaoInterface(int option);
// };

// #endif