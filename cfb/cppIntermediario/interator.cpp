//Esse código usa algumas funções do iterator no vector
#include <iostream>
#include <vector>


int main()
{
    std::vector<std::string> carros={"F150", "Mustang", "Dodge HellCat"};
    std::vector<std::string>::iterator it;

    //Pegando a posição inicial do vector e colocando ela no iterator
    it = carros.begin();

    //std::advance(it,2);

    for(it=carros.begin(); it != carros.end(); it++)
    {
        std::cout << *it << '\n';
    }

}
