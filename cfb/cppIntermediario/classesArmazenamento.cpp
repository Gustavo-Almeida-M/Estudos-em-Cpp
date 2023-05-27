//código usando auto e static
#include <iostream>
#include <vector>

void somador()
{
    static auto i{0};
    i++;
    std::cout << i << '\n';
}

int main()
{
    std::vector<int> valores{1,2,3,103,5,6};

    for(auto it = valores.begin(); it!=valores.end(); it++)
    {
        std::cout << *it << '\n';
    }

    std::cout << "Somador: \n";
    somador();
    somador();
    somador();
    somador();
    
}