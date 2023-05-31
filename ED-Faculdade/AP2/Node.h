/*
 * ELYSSON ALVES DE LACERDA - 536587
 * GUSTAVO ALMEIDA MONTEIRO - 538907
*/

#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node{
    Node* nextdireita;
    Node* nextbaixo;
    int linha;
    int coluna;
    double valor;

    Node(double valor, int linha, int coluna, Node* nextDireita, Node* nextBaixo){
        this->valor = valor;
        this->coluna = coluna;
        this->linha = linha;
        this->nextdireita = nextDireita;
        this->nextbaixo = nextBaixo;
    }
};

#endif