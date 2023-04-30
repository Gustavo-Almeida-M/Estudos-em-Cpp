#include <iostream>

void ordenaArray(int array[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam; j++)
        {
            if(array[i] < array[j])
            {
                int aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

int main()
{
    int tamanhoArray;

    std::cout << "Digite o tamanho do Array:";
    std::cin >> tamanhoArray;

    int *array = new int[tamanhoArray];
    
    
    std::cout << "Digite os valores do array: \n";
    for(int i = 0; i < tamanhoArray; i++)
    {
        std::cin >> array[i];
    }
    ordenaArray(array, tamanhoArray);
    for(int i = 0; i < tamanhoArray; i++)
    {
        std::cout << array[i] << '\n';
    }
}