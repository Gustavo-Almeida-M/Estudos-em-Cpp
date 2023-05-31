#include <iostream>
#include "SparseMatrix.h"
#include <fstream>

SparseMatrix* readSparseMatrix(std::string filename){  // Complexidade : O(n)
    std::ifstream file(filename);
    int linhas, colunas, linha, coluna;
    double value;

    file >> linhas >> colunas;
    SparseMatrix* matrix = new SparseMatrix(linhas, colunas);
    while(file >> linha >> coluna >> value){
            matrix->insert(linha, coluna, value);
    }

    return matrix;
}

SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){ //O(n²)
        if(A->getLinhas() == B->getLinhas() && A->getColunas() == B->getColunas()){
            SparseMatrix* aux = new SparseMatrix(A->getLinhas(), A->getColunas()); // Cria uma matriz auxiliar
            for(int i =1; i <= A->getLinhas(); i++){ // Percorre as linhas
                for(int j = 1; j <= A->getColunas(); j++){  // Percorre as colunas
                    aux->insert(i, j, A->get(i, j) + B->get(i, j));  // Insere o valor da soma na matriz auxiliar
                }
            }
            return aux; // Retorna a matriz auxiliar
        }
        else{
            throw std::runtime_error("As matrizes não podem ser somadas");
        }
}

SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B){ //O(n³)
    if(A->getColunas() == B->getLinhas()){
        SparseMatrix* aux = new SparseMatrix(A->getLinhas(), B->getColunas());

        for (int i = 1; i <= aux->getLinhas(); i++){ // Percorrer as linhas
            for (int j = 1; j <= aux->getColunas(); j++){ // Percorrer as colunas
                double temp = 0;
                for (int k = 1; k <= A->getColunas(); k++){ // Realizar a multiplicação
                    temp += A->get(i, k) * B->get(k, j);
                }       
                aux->insert(i, j, temp);
            }
        }
        return aux;
    }else{
        throw std::runtime_error("As matrizes não podem ser multiplicadas");
    }
}