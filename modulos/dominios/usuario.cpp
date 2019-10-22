#include "../../include/usuario.hpp"
#include <iostream>
#include <ctype.h>
using namespace std;

Usuario::Usuario(string cpf, string password)
{

    if (!cpfValido(cpf))
    {
        throw invalid_argument("CPF inválido: verifique a existência de Letras ou símbolos fora de posição.");
    }
    else
    {
        this->cpf = cpf;
    }

    if (!senhaValida(password))
    {
        throw invalid_argument("Senha não bate os requisitos: Certifique-se que contém uma letra maiúscula, uma minúscula e um número.");
    }
    else
    {
        this->senha = password;
    }
}

int Usuario::cpfValido(string code)
{
    // Função de validação do CPF inserido: 1 CPF válido, 0 CPF inválido
    if (code.size() != 14 && code.size() != 11)
    {
        // Caso o CPF não esteja na forma XXX.XXX.XXX-XX nem XXXXXXXXXXX
        return 0;
    }
    else
    {
        if (checaNumerosEmString(code))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int Usuario::checaNumerosEmString(string code)
{
    // Checa se há alguma letra na string passada.
    // Letra encontrada retorna 0, letra não encontrada retorna 1

    for (unsigned int i = 0; i < code.size(); ++i)
    {
        if (!isdigit(code[i]))
        {
            if (!(code.size() == 14 && (((i == 3 || i == 7) && code[i] == '.') || (i == 11 && code[i] == '-'))))

            {
                /*  Em casos que o tamanho seja 14, caso o cpf possua '.' na posição 3 e 7, ou '-' na posição 11, o cpf ainda esta valido.   */
                return 0;
            }
        }
    }
    return 1;
}

int Usuario::senhaValida(string password)
{
    bool maiuscula = false, minuscula = false, numero = false;
    for (unsigned int i = 0; i < password.size(); i++)
    {
        if (isupper(password[i]))
        {
            maiuscula = true;
        }
        else if (islower(password[i]))
        {
            minuscula = true;
        }
        else if (isdigit(password[i]))
        {
            numero = true;
        }
    }
    if (maiuscula && minuscula && numero)
    {
        return 1;
    }
    return 0;
}

bool Usuario::comparaSenha(string password)
{
    if (password == getSenha())
    {
        return true;
    }
    return false;
}
