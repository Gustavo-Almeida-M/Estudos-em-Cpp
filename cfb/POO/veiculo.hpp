#ifndef veiculo
#define veiculo
#include <iostream>

class Veiculo
{
    public:
    int vel;
    int numRodas = 2;
    float tamanhoMotor;
    void setBlindado(bool tipo);
    void impB();

    private:
    bool blindado = true;

};

void Veiculo::setBlindado(bool tipo)
    {
        blindado = tipo;
    }
    void Veiculo::impB()
    {
        if(blindado)
        {
            std::cout << "É blindado\n";
        }
        else
        {
            std::cout << "Não e blindado\n";
        }
    }


class Moto:public Veiculo
{
    public:
    Moto();
};

Moto::Moto()
{
    vel = 30;
    numRodas = 2;
    tamanhoMotor = 0.3;
}

#endif