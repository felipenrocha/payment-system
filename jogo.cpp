#include "jogo.hpp"

static list<string> estados = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE",

                               "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
;

Jogo::Jogo(string code, string name, string city, string state, int type)
{
    if (!codigoValido(code)) // Checa validade do código.
    {
        throw invalid_argument("Código de jogo inválido, certifique-se que seja um número XXX onde X está entre 0-9");
    }
    else
    {
        this->codigoDoJogo = code;
    }
    if (!nomeECidadeValido(name)) // Checa validade do nome.
    {
        throw invalid_argument("Nome de jogo inválido, certifique-se de que não há espaços múltiplos, caractéres especiais ou números.");
    }
    else
    {
        this->nomeDoJogo = name;
    }
    if (!nomeECidadeValido(city)) // Checa validade da Cidade.
    {
        throw invalid_argument("Cidade inválida, certifique-se de que não há espaços múltiplos, caractéres especiais ou números.");
    }
    else
    {
        this->cidade = city;
    }
    if (!estadoValido(state))
    {
        throw invalid_argument("Estado Inválido");
    }
    else
    {
        this->estado = state;
    }
    if (!tipoValido(type))
    {
        throw invalid_argument("Tipo inválido de jogo.");
    }
    else
    {
        this->tipoDoJogo = type;
    }
}

int Jogo::codigoValido(string code)
{
    for (int i = 0; i < code.size(); i++)
    {
        if (!isdigit(code[i]))
        {
            return 0;
        }
    }
    return 1;
}

int Jogo::nomeECidadeValido(string name)
{
    for (int i = 0; i < name.size(); i++)
    {

        if (i > 0 && name[i] == ' ' && name[i - 1] == ' ') // Tiver dois espaços seguidos.
        {

            return 0;
        }
        else if (!isalpha(name[i]) && name[i] != '.' && name[i] != ' ') // Caracteres especiais e numeros tirando o " . " e espaço
        {
            return 0;
        }
    }
    return 1;
}
int Jogo::estadoValido(string state)
{

    for (auto const &i : estados)
    {
        if (i == state)
        {
            return 1;
        }
    }
    return 0;
}
int Jogo::tipoValido(int type)
{
    if (type >= 1 && type <= 4)
    {
        return 1;
    }
    return 0;
}

string Jogo::getTipoDoJogo()
{
    switch (getTipo())
    {
    case 1:
        return "LOCAL";
    case 2:
        return "ESTADUAL";
    case 3:
        return "NACIONAL";
    case 4:
        return "INTERNACIONAL";
    }
}
