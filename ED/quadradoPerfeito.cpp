#include <iostream>

int main()
{
    int matriz[3][3];
    int soma[3];
    int somaDiagonalBaixo = 0;
    int somaDiagonalCima = 0;
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
    for(int i = 0; i < 3; i++)
    {
        somaDiagonalBaixo += matriz[i][i];
    }
    for(int i = 2; i >= 0; i--)
    {
        int posicao = 0;
        somaDiagonalCima += matriz[i][posicao];
        posicao++;
    }
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