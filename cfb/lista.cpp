#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> valores;

    list<int> segundo;
    segundo.push_back(2222);
    segundo.push_back(2222);
    segundo.push_back(2222);



    int tamanho = 10;
    list<int>::iterator it;


    for (int i = 0; i < tamanho; i++)
    {
        valores.push_back(i);
    }
    

    //Adicionando um valor em um possição especifica.
    it = valores.begin();
    advance(it, 6);
    valores.insert(it, 105);

    //Junta duas listas
    valores.merge(segundo);

    //Exclui o valor da possição determinada
    //valores.erase(--it);

    //Essa função ordena os valores, do menor para o maior
    //valores.sort();

    //Inverte os valores.
    //valores.reverse();

    tamanho = valores.size();
    for (int i = 0; i < tamanho; i++)
    {
        cout << valores.front() << "\n";
        valores.pop_front();
    }
}