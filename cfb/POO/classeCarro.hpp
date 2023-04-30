#ifndef carroClass
#define carroClass 

#include <iostream>

class carro
{
    public:
    int qtdPnel = 4;
    int numPortas = 2;
    std::string nomeCarro = "nada";
    
    void ini(int tp);
    
};

void carro::ini(int tp)
{
    if(tp == 1)
    {
        this->nomeCarro = "Mclaren";
    }
    else if(tp == 2)
    {
        this->nomeCarro = "Ferrari";
    }
}
#endif