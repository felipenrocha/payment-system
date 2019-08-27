#ifndef USUARIO_HPP_INCLUDED
#define USUARIO_HPP_INCLUDED
#include <string>
using namespace std;


class Usuario
{
private:
    string cpf;
    string senha;

protected:
    int cpfValido(string code);
    string getSenha() { return senha; }
    int senhaValida(string password);
    int checaNumerosEmString(string code);
    int charEhNumero(char digito);

public:
    Usuario(string cpf , string senha);
    string getCpf() { return cpf; }
    int comparaSenha(string password);
};

Usuario cadastraUsuario();

#endif // USUARIO_HPP_INCLUDED
