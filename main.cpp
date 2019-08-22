#include <iostream>
#include "codigo.hpp"
using namespace std;

int main()
{
    

    CodigoDoJogo code;
    code.alocaCodigo();
    code.setCodigo("123");
    cout << "Codigo setado: " << code.getCodigo() << endl;

    return 0;
}
