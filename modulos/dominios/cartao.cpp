#include "../../include/cartao.hpp"

Cartao::Cartao(string number, string code, string date)
{
    /**
     * @brief
     * Construtor da classe Catão, a ideia é validar todos os atributos de acordo com sua estrutura e retornar uma
     * mensagem de exceção caso aquele caso seja inválido. A classe só é criada se todos os argumentos são válidos.
     * 
     */
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
    /**
    * Se o número de cartão passado possuir uma quantidade de caractéres diferente de 16, ou não
    * passar no algoritmo de Luhn, o número é inválido. 
    */
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
    /**
     * O código é válido se possuir 3 caractéres e todas forem digitos. 
     */

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
    /**
     * 1.A data é valida se possuir um tamanho == 5, o 3 º char como '/' e os restantes digitos; 
     * 2.Depois são pegados o mes e ano separadamente e transformados em um valor inteiro com a funçã "int atoi(const char)";
     * 3.Por último é checado se aqueles números são válidos como meses e anos;
     */

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

    /**
     * @brief 
     * O algoritmo de Luhn é um algoritmo específico utilizado na validação de números de cartão de crédito.
     * uma explicação mais elaborada pode ser encontrada em https://en.wikipedia.org/wiki/Luhn_algorithm, e
     * existe uma página na internet que checa o processo automaticamente: https://www.dcode.fr/luhn-algorithm
     */

    int numeroDigitos = number.size();
    int soma = 0;
    bool segundoNumero = false;
    for (int i = numeroDigitos - 1; i >= 0; i--)
    {
        /* Um número em "inteiro" em char menos o valor '0' é seu resultado em inteiro,
        uma vez que chars são interpretados como inteiros.
        */
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
}