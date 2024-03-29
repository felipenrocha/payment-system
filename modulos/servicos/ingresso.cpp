#include "../../include/ingresso.hpp"

Ingresso::Ingresso(string code) : Singleton()
{
    /**
     * @brief O construtor do ingresso irá instanciar um objeto caso o código do ingresso seja válido.
     */
    this->id = this->getInstancia();
    if (codigoValido(code))
    {
        this->codigo = code;
    }
    else
    {
        throw invalid_argument("Certifique-se de que seja um código válido (Formato XXXXX onde X é dígito (0 – 9)).");
    }
}

int Ingresso::codigoValido(string code)
{
    /**
     * O código é válido se possuir tamanho 5 e todos seus valores forem digitos. 
     */
    if (code.size() != 5)
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