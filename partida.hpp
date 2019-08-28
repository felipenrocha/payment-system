#ifndef __PARTIDA_HPP__
#define __PARTIDA_HPP__
#include <iostream>
#include <string>
#include <ctype.h>
#include <list>
using namespace std;

class Partida
{
private:
    int numeroDeSala;
    string data;
    string horario;
    double preco;
    int disponibilidade;

protected:
    int numeroValido(int number);
    int dataValida(string date);
    int horarioValido(string time);
    int precoValido(double price);
    int disponibilidadeValida(int disponibilty);
public:
    Partida(int number, string date, string time, double price, int disponibility);

};

#endif // __PARTIDA_HPP__