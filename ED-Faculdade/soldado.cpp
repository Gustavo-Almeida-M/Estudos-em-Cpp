#include <iostream>

int main()
{
    int linhas, colunas;
    std::cin >> linhas >> colunas;

    int soldados[linhas][colunas];
    int soma = 0;
    
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            std::cin >> soldados[i][j];
        }
    }
    for(int i = 1; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            if(soldados[i][j] < soldados[i - 1][j])
            {
                soma++;
            }
        }
    }
    std::cout << soma;
}