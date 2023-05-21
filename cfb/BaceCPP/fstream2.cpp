#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
    std::fstream arquivo;

    char opc = 's';
    std::string nome;
    arquivo.open("armas.txt", std::ios::out);

    while(opc == 's')
    {
        std::cout << "Digite o nome de uma arma\n";
        std::getline(std::cin, nome);
        //std::cin >> nome;

        arquivo << nome << '\n';

        std::cout << "Deseja digitar um novo nome?";
        std::cin >> opc;
        std::cin.ignore();

        system("CLS");
    }

    arquivo.close();

    arquivo.open("armas.txt", std::ios::in);
    std::string armas;


    if(arquivo.is_open())
    {
        while(std::getline(arquivo, armas))
        {
            std::cout << armas << '\n';
        }  
    }
    else 
    {
        std::cout << "Não foi possivel abrir\n";
    }
}