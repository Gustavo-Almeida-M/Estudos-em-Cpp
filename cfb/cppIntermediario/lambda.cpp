#include <iostream>
#include <vector>

int main()
{
    int v1,v2,v3;
    v1 = 10;
    v2 = 5;
    v3 = 30;


    auto menor = [=](std::vector<int> n)->auto
    {
        auto menorV = n[0];
        for(auto i : n)
        {
            menorV = (i < menorV)?i: menorV;
        }
        return menorV + v1;
    };


    auto soma = [=]()->int
    {
        return v1 + v2 + v3;
    };


    std::cout << menor({20, 40, 50, 234}) << '\n' << soma();
}