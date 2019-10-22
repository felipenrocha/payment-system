#include "../../include/jogo.hpp"

/**
 * @brief Para checagem dos estados foi criada uma lista estática que contem os valores das abreviações dos estados,
 * que será checada para validar se a entrada do Usuário foi válida. 
 */
static list<string> estados = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE",

                               "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
;

Jogo::Jogo(string code, string name, string city, string state, int type)
{

    /**
 * @brief O construtor do jogo recebe um código, nome, cidade estado e tipo de jogo. O jogo é instanciado
 * caso todos os atributos estejam válidos. 
 */

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
    if (!estadoValido(state)) // Checa validade do estado
    {
        throw invalid_argument("Estado Inválido");
    }
    else
    {
        this->estado = state;
    }
    if (!tipoValido(type)) // Checa validade do tipo
    {
        throw invalid_argument("Tipo inválido de jogo.");
    }
    else
    {
        this->tipoDoJogo = type;
    }
}

int Jogo::codigoValido(string code)
/**
 * O código é válido se tiver tamanho 3 e todos valores forem digitos. 
 */
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

int Jogo::nomeECidadeValido(string name)
{
    /**
    * O Nome ou cidade são válidos se não possuirem 2 espaços seguidos ou possuir caracteres especiais,
    * números, com exceção do . e barra de espaço.
    */
    for (unsigned int i = 0; i < name.size(); i++)
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
    /**
     * O estado é válido se for um valor contido na lista de estados. Para isso é feito um loop
     * na lista e caso os valores sejam iguais, a função retorna 1.
     */

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
    /**
     * O tipo do jogo é valido se estiver entre 1 e 4.
     */
    if (type >= 1 && type <= 4)
    {
        return 1;
    }
    return 0;
}

string Jogo::getTipoDoJogo()
{
    /**
     * Essa função é feita para retornar o nome do jogo para cada tio específico.
     */
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
    return NULL;
}
