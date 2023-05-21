#include <iostream>
#include <fstream>

int main()
{
    std::ofstream arquivoS;

    arquivoS.open("Carros.txt");

    arquivoS << "Vectra, hilux, S10, chevette";

    arquivoS.close();

    std::ifstream arquivoE;

    std::string linha;
    arquivoE.open("Carros.txt", std::ios::app);

    if(arquivoE.is_open())
    {
        std::getline(arquivoE, linha);
        std::cout << linha << '\n';
        arquivoE.close();
    }
    else 
    {
        std::cout << "Não foi possivel abrir\n";
    }
}