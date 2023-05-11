#include <iostream>
#include <fstream>

int main()
{
    std::ofstream arquivo;

    arquivo.open("Carros.txt", std::ios::app);

    arquivo << " Vectra, hilux, S10, chevette";

    arquivo.close();
}