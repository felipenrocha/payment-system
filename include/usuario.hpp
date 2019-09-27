#ifndef USUARIO_HPP_INCLUDED
#define USUARIO_HPP_INCLUDED
#include <string>
using namespace std;

class Usuario
{
/**
* Classe responsável por conter o domínio Usuario
*/
private:
/**
* Entidades: 
*/
    string cpf;
    string senha;

protected:
    int cpfValido(string code);
    string getSenha() { return senha; }
    int senhaValida(string password);
    int checaNumerosEmString(string code);
    int charEhNumero(char digito);

public:
    Usuario(string cpf, string senha);
    string getCpf() { return cpf; }
    bool comparaSenha(string password);
};

Usuario cadastraUsuario();

#endif // USUARIO_HPP_INCLUDED
