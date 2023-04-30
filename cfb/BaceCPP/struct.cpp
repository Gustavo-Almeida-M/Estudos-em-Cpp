#include <iostream>

using namespace std;

struct car
{
    int velocidadeMax;
    void velocidadePermitida(int vel)
    {
        if(vel > velocidadeMax || vel < 0)
        {
            cout << "Velocidade invalida";
        }
        else
        {
            cout << "Velocidade Permitida";
        }
    }
};

int main()
{
    car carro1 {250};
    int velocidade = 0;
    cout << "Digite a velocidade do carro: \n";
    cin >> velocidade;
    carro1.velocidadePermitida(velocidade);
}