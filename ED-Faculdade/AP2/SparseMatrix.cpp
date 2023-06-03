/*
 * ELYSSON ALVES DE LACERDA - 536587
 * GUSTAVO ALMEIDA MONTEIRO - 538907
*/

#include <iostream>
#include <stdexcept>
#include "SparseMatrix.h"

// Implementação do Construtor
SparseMatrix::SparseMatrix(int linha, int coluna)
{
    this->m_linha = linha;
    this->m_coluna = coluna;

    this->m_head = new Node(0, 0, 0, nullptr, nullptr);
    Node* aux = this->m_head;

    // Criar nós cabeçalho na direção direita
    for (int i = 1; i <= coluna; i++) 
    {
        aux->nextdireita = new Node(0, 0, i, nullptr, nullptr);
        aux = aux->nextdireita;
        aux->nextdireita = this->m_head;
        aux->nextbaixo = aux;
    }

    aux = this->m_head;

    // Criar nós cabeçalho na direção baixo e ler os valores da matriz
    for (int i = 1; i <= linha; i++) 
    {
        aux->nextbaixo = new Node(0, i, 0, nullptr, nullptr);
        aux = aux->nextbaixo;
        aux->nextdireita = this->m_head;

        for (int j = 1; j <= coluna; j++)
        {
            double valor;
            std::cout << "Digite o valor para a posicao [" << i << ", " << j << "]: ";
            std::cin >> valor;
            insert(i, j, valor);
        }

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

void SparseMatrix::insert(int linha, int coluna, double valor){ // Complexidade : O(n)
    if (linha > this->m_linha || coluna > this->m_coluna || linha < 1 || coluna < 1)
    {
        throw std::out_of_range("Posicao invalida");
    }

    Node* aux1 = this->m_head->nextbaixo;
    Node* aux2 = this->m_head->nextdireita;

    while (aux1->linha != linha)
        aux1 = aux1->nextbaixo;

    while (aux2->coluna != coluna)
        aux2 = aux2->nextdireita;

    while (aux1->nextdireita->coluna < coluna && aux1->nextdireita->coluna != 0)
        aux1 = aux1->nextdireita;

    while (aux2->nextbaixo->linha < linha && aux2->nextbaixo->linha != 0)
        aux2 = aux2->nextbaixo;

    if (aux1->nextdireita->coluna == coluna && aux2->nextbaixo->linha == linha)
    {   
        if(valor == 0){
            Node* temp1 = aux1->nextdireita->nextdireita;
            Node* temp2 = aux1->nextdireita->nextbaixo;
            delete aux1->nextdireita;
            aux1->nextdireita = temp1;
            aux2->nextbaixo = temp2;
        }
        else{
            aux1->nextdireita->valor = valor;
        }
    } else {
        Node* novo = new Node(valor, linha, coluna, aux1->nextdireita, aux2->nextbaixo);
        aux1->nextdireita = novo;
        aux2->nextbaixo = novo;
    }
     
}
// Remove valores de uma matriz
void SparseMatrix::remove(int linha, int coluna) {
    if (linha > this->m_linha || coluna > this->m_coluna || linha < 1 || coluna < 1) {
        throw std::out_of_range("Posicao invalida");
    }

    Node* aux1 = this->m_head->nextbaixo;
    Node* aux2 = this->m_head->nextdireita;

    while (aux1->linha != linha)
        aux1 = aux1->nextbaixo;

    while (aux2->coluna != coluna)
        aux2 = aux2->nextdireita;

    Node* prev1 = aux1;
    while (aux1->nextdireita != aux1 && aux1->nextdireita->coluna < coluna) {
        prev1 = aux1;
        aux1 = aux1->nextdireita;
    }

    Node* prev2 = aux2;
    while (aux2->nextbaixo != aux2 && aux2->nextbaixo->linha < linha) {
        prev2 = aux2;
        aux2 = aux2->nextbaixo;
    }

    if (aux1->nextdireita->coluna == coluna && aux2->nextbaixo->linha == linha) {
        Node* temp1 = aux1->nextdireita->nextdireita;
        Node* temp2 = aux2->nextbaixo->nextbaixo;
        delete aux1->nextdireita;
        prev1->nextdireita = temp1;
        prev2->nextbaixo = temp2;
    } else {
        throw std::runtime_error("Elemento nao encontrado na matriz esparsa");
    }
}


// Devolver o valor da matrix
double SparseMatrix::get(int linha, int coluna){ // Complexidade : O(n)
    if(linha > this->m_linha || linha < 0 || coluna > this-> m_coluna){
        throw std::range_error("indice invalido");
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
void SparseMatrix::print() 
{
    for (int i = 1; i <= m_linha; i++)
    {
        for (int j = 1; j <= m_coluna; j++)
        {
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
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

SparseMatrix SparseMatrix::copia() const {
    SparseMatrix copiedMatrix(this->m_linha, this->m_coluna);

    Node* aux1 = this->m_head->nextbaixo;
    Node* aux2 = this->m_head->nextdireita;

    while (aux1 != nullptr) {
        Node* current = aux1->nextdireita;
        while (current != nullptr) {
            copiedMatrix.insert(aux1->linha, current->coluna, current->valor);
            current = current->nextdireita;
        }
        aux1 = aux1->nextbaixo;
    }

    return copiedMatrix;
}