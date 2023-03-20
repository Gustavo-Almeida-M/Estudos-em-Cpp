#include <iostream>

bool primo(int valor)
{
    //dividindo por 2 e somando com 1, pois dessa forma nenhum número acima poderar dividir o valor
    for(int i = 2; i < (valor / 2) + 1;i++)
    {
        if(valor %i == 0)
        {
        //Se entrar é pq não é primo
            return false;
        }
    }
    //Caso não entre no if, ele automaticamente é primo
    return true;
}


int main()
{
    int numeroInicial, numeroFinal;
    std::cin >> numeroInicial;
    std::cin >> numeroFinal;
    for(int i = numeroInicial; i <= numeroFinal; i++)
    {
        if(primo(i))
        {
            std::cout << i << std::endl;
        }
    }
}