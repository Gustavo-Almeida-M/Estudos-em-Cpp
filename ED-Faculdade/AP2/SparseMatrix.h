/*
 * ELYSSON ALVES DE LACERDA - 536587
 * GUSTAVO ALMEIDA MONTEIRO - 538907
*/
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "Node.h"
#include <stdexcept>

class SparseMatrix {
private:
    Node* m_head;
    int m_coluna;
    int m_linha;

public:
    SparseMatrix(int coluna, int linha);
    ~SparseMatrix();
    bool insert(int linha, int coluna, double valor);
    void remove(int linha, int coluna);
    double get(int linha, int coluna);
    void print();
    int getColunas();
    int getLinhas();
    SparseMatrix copiar(SparseMatrix *matrix);
};

#endif
