//Programa testando algumas funções do vector
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> num;
    num.push_back(7);
    num.push_back(23);
    num.push_back(45);
    num.push_back(38);
    
    std::vector<int> num2;
    num2.push_back(99);
    num2.push_back(137);
    num2.push_back(3);
    num2.push_back(10);
    
    
    for(int i = 0; i < num.size(); i++)
    {
        std::cout << num[i] << ' ';
    }
    num.swap(num2);
    std::cout << '\n';
    
    for(int i = 0; i < num.size(); i++)
    {
        std::cout << num[i] << ' ';
    }
    
    // std::cout << '\n' << num.at(num.size()/2) << '\n' << num.front() << '\n' << num.back();
    // num.pop_back(); exclui o ultimo elemento
    num.erase(num.begin() + 2);
    std::cout << '\n';
    
    for(int i = 0; i < num.size(); i++)
    {
        std::cout << num[i] << ' ';
    }
    
}