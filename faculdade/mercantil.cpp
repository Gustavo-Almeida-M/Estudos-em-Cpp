#include <iostream>

int main()
{
    int valorProduto;
    std::cin >> valorProduto;
    int jogador1, jogador2;
    std::cin >> jogador1;
    std::cin >> jogador2;
    //Diminuindo para descobrir a diferença.
    jogador1 -= valorProduto;
    jogador2 -= valorProduto;
    //Comparando, para no caso de o número ser negativo.
    if(jogador1 < 0){jogador1 *= -1;}
    if(jogador2 < 0){jogador2 *= -1;}
    //Comparando os valores.
    if(jogador1 == jogador2)
    {
        std::cout << "empate";
        return 0;
    }
    else if(jogador1 < jogador2)
    {
        std::cout << "primeiro";
        return 0;
    }
    else
    {
        std::cout << "segundo";
        return 0;
    }
}