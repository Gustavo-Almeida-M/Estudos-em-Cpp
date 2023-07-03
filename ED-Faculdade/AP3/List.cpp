#include "List.h"
#include <iostream>
#include <vector>

void List::insertionsort(int A[], int inicio, int fim) {
    for(int j = inicio+1; j <= fim; j++) {
        int key = A[j];
        int i = j-1;
        while(i >= inicio && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void List::bubblesort(int A[], int inicio, int fim) {
    for(int i = inicio; i < fim; i++) {
        for(int j = fim; j > i; j--) {
            if(A[j] < A[j-1]) {
                std::swap(A[j],A[j-1]);
            }
        }
    }
}
void List::mergesort(int A[], int inicio, int fim)
{
    if(fim - inicio > 1)
    {
        //encontrando o meio
        int meio = (fim + inicio)/2;
        mergesort(A, inicio, meio);
        mergesort(A, meio, fim);
        merge(A, inicio, meio, fim);
    }
}

void List::merge(int A[], int inicio, int meio, int fim)
{

    std::vector<int> left, right;

    //copiando os elementos ate o meio de A
    for(int i = inicio; i < meio; i++)
    {
        left.push_back(A[i]);
    }
    //copiando os elementos depois da metade
    for(int i = meio; i < fim; i++)
    {
        right.push_back(A[i]);
    }


    int cont1 = 0, cont2 = 0;
    int i = inicio;

    //comparando caso enquanto for possivel
    while (cont1 < left.size() && cont2 < right.size())
    {
        if (left[cont1] < right[cont2])
        {
            A[i] = left[cont1];
            cont1++;
        }
        else
        {
            A[i] = right[cont2];
            cont2++;
        }
        i++;
    }

    //caso onde para left
    while (cont1 < left.size())
    {
        A[i] = left[cont1];
        cont1++;
        i++;
    }
    //caso para right
    while (cont2 < right.size())
    {
        A[i] = right[cont2];
        cont2++;
        i++;
    }

}

void List::quicksort(int A[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int p = partition(A, inicio, fim);
        quicksort(A, inicio, p-1);
        quicksort(A, p+1, fim);
    }
}

int List::partition(int A[], int inicio, int fim)
{
    int pivo = A[fim - 1];
    int i = inicio;
    for(int j = 0; j < fim; j++)
    {
        if(A[j] <= pivo)
        {
            int aux = A[j];
            A[j] = A[i];
            A[i] = aux;
            i++;
        }
    }
    int aux = A[i];
    A[i] = A[fim];
    A[fim] = aux;
    return i;
}