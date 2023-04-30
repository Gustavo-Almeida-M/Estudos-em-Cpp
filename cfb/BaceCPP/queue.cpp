#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue <string> cartas;

    cartas.push("Rei de copas");
    cartas.push("Rainha de espadas");

    cout << "Tamanho da fila = " << cartas.size() << "\n";

    while(!cartas.empty())
    {
        cout << "Primeira carta: " << cartas.front() << "\n";
        cartas.pop();
    }
}