#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> nomes;
    std::map<int, std::string>::iterator proc;

    nomes.insert(std::pair<int, std::string> (0, "Gustavo"));
    nomes.insert(std::pair<int, std::string> (2, "Caio"));
    nomes.insert(std::pair<int, std::string> (1, "Fernando"));

    nomes.erase(nomes.find(1), nomes.find(2));

    proc= nomes.find(1);

    for(auto it : nomes)
    {
        std::cout << it.first << ' ' << it.second << '\n';
    }

    (proc != nomes.end())?std::cout << "Valor encontrado\n" : std::cout << "Produto nao encontrado";
}