#include <iostream>

class Singleton
{
private:
    
    static Singleton *instancia;
    Singleton();

public:
    /* Static access method. */
    static Singleton *getInstancia();
};