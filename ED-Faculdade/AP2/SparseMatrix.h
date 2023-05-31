/*
 * ELYSSON ALVES DE LACERDA - 536587
 * GUSTAVO ALMEIDA MONTEIRO - 538907
*/

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"

class SparseMatrix{
    private:
        Node* m_head{nullptr};
        int m_coluna {0};
        int m_linha {0};
    public:
        // Construtor passando o número de linhas e colunas da matriz
        SparseMatrix(int coluna, int linha);

        // Destrutor
        ~SparseMatrix();

        /**
         * Inserir/Substituir elemento na matriz passando número de linhas e colunas
         * e o valor a ser inserido
        */
       void insert(int linha, int coluna, double valor);

       // Retornar elemento da matriz
       double get(int linha, int coluna);

       // Imprimir a matriz
       void print();

       // Retornar o número de colunas da matriz
       int getColunas();

       // Retonar o número de linhas da matriz
       int getLinhas();
};

#endif