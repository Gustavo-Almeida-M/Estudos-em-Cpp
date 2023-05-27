//Usando try catch
#include <iostream>
#include <stdexcept>

double divicao(double, double);

int main()
{
    double valor1, valor2;

    std::cin >> valor1 >> valor2;

    try
    {
        std::cout << divicao(valor1, valor2) << '\n';
    }
    catch(const char* msg)
    {
        std::cout << "Erro: " << msg;
    }
    
}

double divicao(double v1, double v2)
{
    if(v2 == 0)
    {
        throw "divisao por 0!\n";

    }
    return v1/v2;
}