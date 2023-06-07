#include <iostream>
#include <vector>

int main()
{
    int v1,v2,v3;
    v1 = 10;
    v2 = 5;
    v3 = 30;

    //Calcula o menor elemento
    auto menor = [=](std::vector<int> n)->auto
    {
        auto menorV = n[0];
        for(auto i : n)
        {
            menorV = (i < menorV)?i: menorV;
        }
        return menorV + v1;
    };

    //soma os elementos selecionado
    auto soma = [=]()->int
    {
        return v1 + v2 + v3;
    };

    //teste de sobrecarga;
    [=](int s1, int s2)->int
    {
        return s1 + s2;
    };
    

    std::cout << menor({20, 40, 50, 234}) << '\n' << soma() << '\n' << (v1,v2);
}