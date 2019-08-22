
#include "string.h"

class Codigo
{
public:
    char const *getCodigo() { return codigo; };
    void setCodigo(char const * code) { strcpy(codigo, code); };
    void alocaCodigo() { codigo = new char[tamanho]; };
    virtual int validacaoCodigo() = 0;

private:
    int tamanho;
    char *codigo;
};

class CodigoDoJogo : public Codigo
{
public:
    int validacaoCodigo();

protected:
    int tamanho = 4;
};
class CodigoDoIngresso : public Codigo
{
public:
    int validacaoCodigo();
};
class CodigoDeSeguranca : public Codigo
{
public:
    int validacaoCodigo();
};
class NumeroDoCartao : public Codigo
{
public:
    int validacaoCodigo();
};
