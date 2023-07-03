#include <string>
#include <chrono>
#include <iostream>
#include "List.h"
using namespace std;

void print(int A[], int n) {
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

/**
 * Funcao que calcula o tempo de duracao de um algoritmo de ordenacao
 * @param vec O vetor de inteiros
 * @param l O indice inicial do vetor
 * @param r O indice final do vetor
 * @param f O ponteiro para uma funcao de ordenacao
 * @param name String contendo o nome da funcao de ordenacao
*/
void testa_algoritmoBubblesort(int vec[], int l, int r, List lst, string name) {
    auto start = chrono::steady_clock::now();
    lst.bubblesort(vec, l, r);
    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);

    cout << name << ": " << duration.count() << " microssegundos" << endl;
}
void testa_algoritmoInsertionsort(int vec[], int l, int r, List lst, string name) {
    auto start = chrono::steady_clock::now();
    lst.insertionsort(vec, l, r);
    auto end = chrono::steady_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);

    cout << name << ": " << duration.count() << " microssegundos" << endl;
}
int main()
{
    const int tamanho {30};
    int vec1[tamanho];
    int vec2[tamanho];
    for(int i = 0; i < tamanho; i++) {
        vec1[i] = vec2[i] = rand() % 100;
    }

    List lst;


    // testa_algoritmoBubblesort(vec1, 0, tamanho-1, lst, "bubblesort");
    // testa_algoritmoInsertionsort(vec2, 0, tamanho-1, lst, "insertionsort");
    

    // Imprimir os vetores ordenados
    std::cout << "Vetor ordenado por Bubble Sort: ";
    for (int i = 0; i < tamanho; i++) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Vetor ordenado por Insertion Sort: ";
    for (int i = 0; i < tamanho; i++) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    int valor;

    std::cin >> valor;

    cout << '\n' <<valor;

    return 0;
}


/*
int main() {
    const int tamanho {1000};
    int vec1[tamanho];
    int vec2[tamanho];
    for(int i = 0; i < tamanho; i++) {
        vec1[i] = vec2[i] = rand() % 100;
    }
    testa_algoritmo(vec1, 0, tamanho-1, bubblesort, "bubblesort");
    testa_algoritmo(vec2, 0, tamanho-1, insertionsort, "insertionsort");
}
*/