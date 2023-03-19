#include <iostream>

int main()
{
    int matriz[3][3];
    int soma[3];
    soma[1] = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cin >> matriz[i][j];
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            soma[i] += matriz[i][j]; 
        }
    }
    int somaDiagonalBaixo = matriz[0][0] + matriz[1][1] + matriz[2][2];
    int somaDiagonalCima = matriz[2][0] + matriz[1][1] + matriz[0][2];
    for(int i = 0; i < 3; i++)
    {
        if(soma[i] != somaDiagonalBaixo || soma[i] != somaDiagonalCima)
        {
            std::cout << "nao";
            return 0;
        }
    }
    std::cout << "sim";
}