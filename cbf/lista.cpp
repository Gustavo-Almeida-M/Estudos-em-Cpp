#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> valores;
    int tamanho = 10;
    list<int>::iterator it;


    for (int i = 0; i < tamanho; i++)
    {
        valores.push_back(i);
    }
    tamanho = valores.size();

    //Adicionando um valor em um possição especifica.
    it = valores.begin();
    advance(it, 6);
    valores.insert(it, 105);

    //Essa função ordena os valores, do menor para o maior
    valores.sort();

    //Inverte os valores.
    valores.reverse();

    for (int i = 0; i < tamanho; i++)
    {
        cout << valores.front() << "\n";
        valores.pop_front();
    }
}