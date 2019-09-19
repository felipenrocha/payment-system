#include "./include/cartao.hpp"

Cartao::Cartao(string number, string code, string date)
{
    if (numeroValido(number))
    {
        this->numero = number;
    }
    else
    {
        throw invalid_argument("Número de cartão de crédito inválido. Formato XXXXXXXXXXXXXXXX onde X é dígito (0 – 9). Número inválido segundo o algoritmo de Luhn");
    }

    if (codigoValido(code))
    {
        this->codigo = code;
    }
    else
    {
        throw invalid_argument("Certifique-se de que seja um código de segurança válido (Formato XXX onde X é dígito (0 a 9)).");
    }
    if (dataValida(date))
    {
        this->dataValidade = date;
    }
    else
    {
        throw invalid_argument("Formato inválido, certifique-se que a data se encontra no seguinte formato: MM/AA");
    }
}
int Cartao::numeroValido(string numero)
{
    if (numero.size() != 16)
    {
        return 0;
    }
    if (checaAlgoritmoLuhn(numero))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Cartao::codigoValido(string code)
{
    if (code.size() != 3)
    {
        return 0;
    }
    for (unsigned int i = 0; i < code.size(); i++)
    {
        if (!isdigit(code[i]))
        {
            return 0;
        }
    }
    return 1;
}

int Cartao::dataValida(string date)
{
    if (date.size() != 5)
    {
        return 0;
    }
    if (date[2] != '/')
    {
        return 0;
    }
    if (isdigit(date[0]) && isdigit(date[1]))
    { //Pegando digitos;
        char month[2];
        month[0] = date[0];
        month[1] = date[1];
        int intMonth = atoi(month);

        if (intMonth < 1 || intMonth > 12)
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

    if (isdigit(date[3]) && isdigit(date[4]))
    {
        char year[2];
        year[0] = date[3];
        year[1] = date[4];
        int intYear = atoi(year);

        if (intYear < 0 && intYear > 99)
            return 0;
    }
    else
    {
        return 0;
    }
    return 1;
}

bool Cartao::checaAlgoritmoLuhn(string number)
{
    int numeroDigitos = number.size();
    int soma = 0;
    bool segundoNumero = false;
    for (int i = numeroDigitos - 1; i >= 0; i--)
    {
        int numero = number[i] - '0';
        if (segundoNumero)
        {
            numero = numero * 2; // Posições ímpares: dobra o valor.
        }
        if (numero >= 10)
        {
            numero = numero - 9; // A soma de dos algarismos de um numero >= 10 < 18 é igual ao numero - 9
        }
        soma = soma + numero;
        segundoNumero = !segundoNumero;
    }

    if (soma % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // for (int i = numeroDigitos - 1; i > 0; i--)
    // {
    //     if (!isdigit(number[i]))
    //     {
    //         return false;
    //     }
    //     int value = number[i] - '0';
    //     if (segundoNumero)
    //     {
    //         value = value * 2;
    //     }
    //     soma += value / 10;
    //     soma += value % 10;
    //     cout << "soma inside: " << soma << endl;
    //     segundoNumero = !segundoNumero;
    //     // soma = (soma + number[i] - '0') % 10;
    // }
    // return (soma % 10 == 0);
}