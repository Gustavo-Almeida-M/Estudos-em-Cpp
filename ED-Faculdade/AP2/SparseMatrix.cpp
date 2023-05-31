/*
 * ELYSSON ALVES DE LACERDA - 536587
 * GUSTAVO ALMEIDA MONTEIRO - 538907
*/

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"

// Implementação do Construtor
SparseMatrix::SparseMatrix(int linha, int coluna){
    this->m_linha = linha;
    this->m_coluna = coluna;

    this->m_head = new Node(0, 0 , 0, nullptr, nullptr);
    Node* aux = this->m_head;

    for(int i = 1; i <= coluna; i++){
        aux->nextdireita = new Node(0, 0, i, nullptr, nullptr);
        aux = aux->nextdireita;
        aux->nextdireita = this->m_head;
        aux->nextbaixo = aux;
    }

    aux = this->m_head;
    for(int i = 1; i <= linha; i++){
        aux->nextbaixo = new Node(0, 0, i, nullptr, nullptr);
        aux = aux->nextbaixo;
        aux->nextdireita = this->m_head;
        aux->nextbaixo = aux;
    }
}

// Implementação do Denstrutor
SparseMatrix::~SparseMatrix(){ // Complexidade : O(n²)
    Node* aux = this->m_head->nextdireita;

    while (aux != this->m_head){
        Node* aux2 = aux->nextbaixo;

        while(aux2 != aux){
            Node* temp = aux2->nextbaixo;
            delete aux2;
            aux2 = temp;
        }

        Node* temp = aux->nextdireita;
        delete aux;
        aux = temp;
    }
    
    aux = this->m_head->nextbaixo;
    while(aux != this->m_head){
        Node* temp = aux->nextbaixo;
        delete aux;
        aux = temp;
    }

    delete this->m_head;
}

void insert(int linha, int coluna, double valor){
    // Fazer
}
// Devolver o valor
double SparseMatrix::get(int linha, int coluna){ // Complexidade : O(n)
    if(linha > this->m_linha || linha < 0 || coluna > this-> m_coluna){
        throw std::range_error("índice inválido");
    }
    // nó auxiliar
    Node* aux = this->m_head->nextdireita;

    // percorrer a coluna
    while(aux->coluna != coluna){
        aux = aux->nextdireita;
    }
    aux = aux->nextbaixo;
    // percorrer a linha
    while(aux->linha != linha){
        aux = aux->nextbaixo;
    }

    if(aux->linha == 0){
        return 0;
    }

    return aux->valor;


}
// Imprimir a matriz
void SparseMatrix::print(){
    Node* aux = this->m_head->nextbaixo;
    while(aux != this->m_head){
        Node* temporario = aux->nextdireita;
        for(int i = 1; i <= this->m_coluna; i++){
            if(i != 1){
                std::cout<<" ";
            }
            if(temporario->coluna == i){
                std::cout<<temporario->valor;
                temporario = temporario->nextdireita;
            }else{
                std::cout<< 0;
            }
        }
        std::cout<< std::endl;
        aux = aux->nextbaixo;
    }
}

// Get para as colunas
int SparseMatrix::getColunas(){ // Complexidade : O(1)
    return this->m_coluna;
}

// Get para as linhas
int SparseMatrix::getLinhas(){ // Complexidade : O(1)
    return this->m_linha;
}