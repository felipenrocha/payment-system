#include "include/usuario.hpp"
#include <iostream>
#include <ctype.h>
using namespace std;

Usuario::Usuario(string cpf, string password)
{
    /**
     * O Usuário é instanciado caso seu CPF  e senha sejam válidos.
     */
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
        throw invalid_argument("Senha nao bate os requisitos: Certifique-se que contem uma letra maiuscula, uma minuscula e um numero.");
    }
    else
    {
        this->senha = password;
    }
}

int Usuario::cpfValido(string code)
{
    /**
     * Algoritmo para validação de CPF:
     * 1. Número de caractéres == 14 ( 025.335.231-27)
     * 2. Checa em uma função se os caractéres correspondem aos de um cpdválido.
     * 
     * Retorna 1 caso a função seja válida.
     */

    // Função de validação do CPF inserido: 1 CPF válido, 0 CPF inválido
    if (code.size() != 14)
    {
        // Caso o CPF não esteja na forma XXX.XXX.XXX-XX nem XXXXXXXXXXX
        return 0;
    }
    else
    {
        return (checaNumerosEmString(code));
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
            if (!((((i == 3 || i == 7) && code[i] == '.') || (i == 11 && code[i] == '-'))))

            {
                return 0;
            }
        }
    }
    return 1;
}

int Usuario::senhaValida(string password)
{
    /**
     * Método para checar se a senha possui uma letra maiúscula minúscula e numero.
     * Algoritmo:
     * 1. Três valores booleanos setados em false;
     * 2. Loop pela string;
     *  2.1 Se um valor maiusculo é encontrado a variavel maiuscula é setada para true;
     *  2.2 e 2.3 Análago ao 2.1 com suas respectivas especificações;
     * 3. Se as três variáveis ao final da iteração forem verdadeiras, a senha é válida.
     * 
     */
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
    /**
     * Função utilizada para comparar a senha do usuario instanciada com uma passada qualquer (validação)
     */
    if (password == getSenha())
    {
        return true;
    }
    return false;
}
