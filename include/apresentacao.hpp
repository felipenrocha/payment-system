#ifndef __APRESENTACAO_HPP__
#define __APRESENTACAO_HPP__
#include <iostream>
#include <string>
using namespace std;

class Apresentacao
{
public:
    virtual string getIdtoRemove() = 0;
    virtual string getIdtoUpdate() = 0;
    virtual int getFieldToUpdate() = 0;
};


#endif