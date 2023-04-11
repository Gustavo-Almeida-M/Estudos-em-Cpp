#include <iostream>

using namespace std;

int main()
{
    enum armas{metralhadora = 30, rifle = 10, pistola = 15, espingarda = 7};

    armas select = metralhadora;
    armas select2 = pistola;

    cout << "Metralhadora : " << select ;
    cout << "\nPistola : " << select ;
}