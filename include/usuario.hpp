#ifndef USUARIO_HPP_INCLUDED
#define USUARIO_HPP_INCLUDED
#include <string>
#include "singleton.hpp"
using namespace std;

class Usuario : public Singleton
{
    /**
* Classe responsável por conter o domínio Usuario
*/
private:
    /**
* Entidades: 
*/
    Singleton *id;
    string cpf;
    string senha;

protected:
    int cpfValido(string code);
    int senhaValida(string password);
    int checaNumerosEmString(string code);
    int charEhNumero(char digito);

public:
    Usuario() : Singleton()
    {
        this->id = NULL;
        this->instancia = 0;
    }
    Usuario(string cpf, string senha);
    string getSenha() { return senha; }
    string getCpf() { return cpf; }
    Singleton *getId() { return id; }
    bool comparaSenha(string password);
};

Usuario cadastraUsuario();

#endif // USUARIO_HPP_INCLUDED
