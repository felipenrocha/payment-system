#include "partida.hpp"

Partida::Partida(int number, string date, string time, double price, int disponibility)
{
    if (numeroValido(number))
    {
        this->numeroDeSala = number;
    }
    else
    {
        throw invalid_argument("Número de sala inválido, certifique-se que seja um número entre 1 a 10");
    }
    if (dataValida(date))
    {
        this->data = date;
    }
    else
    {
        throw invalid_argument("Formato inválido, certifique-se que a data se encontra no seguinte formato: DD/MM/AA");
    }
    if (horarioValido(time))
    {
        this->horario = time;
    }
    else
    {
        throw invalid_argument("Horario invalido, certifique-se de que o horário se encontre entre 7:00 e 22:45 e os minutos sejam 00,15,30,45");
    }
    if (precoValido(price))
    {
        this->preco = price;
    }
    else
    {
        throw invalid_argument("Preço inválido, certifique-se que esteja entre 0 e 1000.");
    }
    if (disponibilidadeValida(disponibility))
    {
        this->disponibilidade = disponibility;
    }
    else
    {
        throw invalid_argument("Disponibilidade inválida, certifique-se de que seja um numero entre 1 e 250.");
    }
}

int Partida::numeroValido(int number)
{
    if (number > 0 && number < 11)
    {
        return 1;
    }
    return 0;
}

int Partida::dataValida(string date)
{
    if (date.size() != 8)
    {

        return 0;
    }
    if (date[2] != '/' || date[5] != '/')
    {

        return 0;
    }
    if (isdigit(date[0]) && isdigit(date[1]))
    { //Pegando digitos;
        char day[2];
        day[0] = date[0];
        day[1] = date[1];
        int intDay = atoi(day);

        if (intDay < 1 || intDay > 31)
            return 0;
    }
    else
    {

        return 0;
    }
    if (isdigit(date[3]) && isdigit(date[4]))
    {
        char month[2];
        month[0] = date[3];
        month[1] = date[4];
        int intMonth = atoi(month);

        if (intMonth < 1 || intMonth > 12)
            return 0;
    }
    else
    {

        return 0;
    }
    if (isdigit(date[6]) && isdigit(date[7]))
    {
        char year[2];
        year[0] = date[6];
        year[1] = date[7];
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

int Partida::horarioValido(string time)
{
    if (time.size() != 5)
        return 0;
    if (time[2] != ':')
        return 0;
    if (isdigit(time[0]) && isdigit(time[1]))
    { //Pegando digitos;
        char hour[2];
        hour[0] = time[0];
        hour[1] = time[1];
        int intHour = atoi(hour);
        if (intHour < 7 || intHour > 22)
            return 0;
    }
    else
    {
        return 0;
    }

    if (isdigit(time[3]) && isdigit(time[4]))
    { 
        char minutes[2];
        minutes[0] = time[3];
        minutes[1] = time[4];
        int intMinutes = atoi(minutes);
        if (intMinutes != 0 && intMinutes != 15 && intMinutes != 30 && intMinutes != 45)
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    return 1;
}
int Partida::precoValido(double price)
{
    if (price < 0 || price > 1000)
        return 0;

    return 1;
}

int Partida::disponibilidadeValida(int disponibility)
{
    if (disponibility < 1 || disponibility > 250)
    {
        return 0;
    }
    return 1;
}