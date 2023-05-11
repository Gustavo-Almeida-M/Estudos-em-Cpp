#include <iostream>
#include "veiculo.hpp"

int main()
{
    Moto *v1 = new Moto();

    // std::cout << v1->numRodas;

    v1->setBlindado(false);
    v1->impB();

}