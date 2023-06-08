#include <iostream>
#include <utility>

int main()
{
    std::pair<int, std::string> dados[1];
    std::pair<int, std::pair<std::string, double>>produto[1];

    dados[0] = std::make_pair(10, "Gustavo");
    produto[0] = std::make_pair(2, std::make_pair("Mouse", 123.7));

    std::cout << dados[0].first << " " << dados[0].second << '\n';

    std::cout << produto[0].first << ' ' << produto[0].second.first << ' ' << produto[0].second.second;

}