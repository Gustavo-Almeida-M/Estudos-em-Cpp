#include <iostream>
#include "classeCarro.hpp"


int main()
{
    carro *carro1 = new carro();
    int tipo;
    std::cin >> tipo;
    
    carro1->ini(tipo);
    std::cout << carro1->nomeCarro;
    
}