#include <iostream>

int main()
{
    int numeroDePecas;
    std::cin >> numeroDePecas;
    int dominos[numeroDePecas];
    
    for(int i = 0; i < numeroDePecas; i++)
    {
        std::cin >> dominos[i];
    }
    for(int i = 1; i < numeroDePecas; i++)
    {
        int valorComparacao = dominos[0];
        if(sizeof(dominos) == 4)
        {
            std::cout << "ok";
            return 1;
        }
        else if(dominos[i - 1] > dominos[i])
        {
            std::cout << "precisa de ajuste";
            return 0;
        }
    }
    std::cout << "ok";
}