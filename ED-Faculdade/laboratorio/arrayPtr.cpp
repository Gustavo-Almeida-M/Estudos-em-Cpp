#include <iostream>

using namespace std;

void leitor(int *ptr, int tamanho)
{
    cout << "Digite os valores do array\n";
    for(int i = 0; i < tamanho; i++)
    {
        cin >> ptr[i];
    }
}
void imprimir(int *ptr, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        cout << ptr[i] << "\n";
    }
}

int main()
{
    int tamanho;
    cout << "Digite o tamanho do array\n";
    cin >> tamanho;
    int *ptr = new int[tamanho];
    leitor(ptr, tamanho);
    imprimir(ptr, tamanho);
    delete[] ptr;
    ptr = nullptr;
}
