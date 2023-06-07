/*
 * ELYSSON ALVES DE LACERDA - 536587
 * GUSTAVO ALMEIDA MONTEIRO - 538907
*/
#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(int coluna, int linha) : m_coluna(coluna), m_linha(linha){
    // Inicializa a cabeça da matriz esparsa
    m_head = new Node(0, 0, 0, nullptr, nullptr);
}

SparseMatrix::~SparseMatrix() {
    // Libera a memória alocada pelos nós da matriz esparsa
    Node* current = m_head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->nextbaixo;
        delete temp;
    }
}

void SparseMatrix::insert(int linha, int coluna, double valor)
{
    if (linha < 0 || linha > m_linha || coluna < 0 || coluna > m_coluna)
    {
        std::cout << "Posicao invalida." << std::endl;
        return;
    }

    // Encontra o nó anterior na mesma linha
    Node* prevRow = nullptr;
    Node* currentRow = m_head;
    while (currentRow->nextbaixo != nullptr && currentRow->nextbaixo->linha < linha) {
        prevRow = currentRow->nextbaixo;
        currentRow = currentRow->nextbaixo;
    }

    // Encontra o nó anterior na mesma coluna
    Node* prevCol = nullptr;
    Node* currentCol = m_head;
    while (currentCol->nextdireita != nullptr && currentCol->nextdireita->coluna < coluna) {
        prevCol = currentCol->nextdireita;
        currentCol = currentCol->nextdireita;
    }

    // Verifica se o nó já existe
    if (currentRow->nextbaixo != nullptr && currentRow->nextbaixo->linha == linha && currentRow->nextbaixo->coluna == coluna) {
        currentRow->nextbaixo->valor = valor;
    } else {
        // Cria um novo nó
        Node* newNode = new Node(valor, linha, coluna, currentCol->nextdireita, currentRow->nextbaixo);

        // Atualiza os ponteiros para inserir o novo nó
        if(prevRow != nullptr)
        {
            prevRow->nextbaixo = newNode;
        }
        else
        {
            m_head->nextbaixo = newNode;
        }

        if(prevCol != nullptr)
        {
            prevCol->nextdireita = newNode;
        }
        else
        {
            m_head->nextdireita = newNode;
        }
    }
}



double SparseMatrix::get(int linha, int coluna) {
    if (linha < 0 || linha >= m_linha || coluna < 0 || coluna >= m_coluna) {
        std::cout << "Posicao invalida." << std::endl;
        return 0;
    }

    Node* current = m_head->nextbaixo;
    while (current != nullptr) {
        if (current->linha == linha && current->coluna == coluna) {
            return current->valor;
        }
        current = current->nextbaixo;
    }

    return 0;
}


void SparseMatrix::print() {
    for (int i = 0; i < m_linha; i++) 
    {
        std::cout << "| ";
        for (int j = 0; j < m_coluna; j++) {
            std::cout << get(i, j) << " ";
        }
        std::cout << "| ";
        std::cout << std::endl;
    }
}


int SparseMatrix::getColunas(){
    return m_coluna;
}

int SparseMatrix::getLinhas(){
    return m_linha;
}

void SparseMatrix::remove(int linha, int coluna) {
    if (linha < 0 || linha >= m_linha || coluna < 0 || coluna >= m_coluna) {
        std::cout << "Posicao invalida." << std::endl;
        return;
    }

    Node* prevRow = nullptr;
    Node* currentRow = m_head->nextbaixo;  // Inicia a partir do primeiro nó da linha
    while (currentRow != nullptr && currentRow->linha < linha) {
        prevRow = currentRow;
        currentRow = currentRow->nextbaixo;
    }

    Node* prevCol = nullptr;
    Node* currentCol = m_head->nextdireita;  // Inicia a partir do primeiro nó da coluna
    while (currentCol != nullptr && currentCol->coluna < coluna) {
        prevCol = currentCol;
        currentCol = currentCol->nextdireita;
    }

    if (currentRow != nullptr && currentRow->linha == linha && currentRow->coluna == coluna) {
        if (prevRow != nullptr) {
            prevRow->nextbaixo = currentRow->nextbaixo;
        } else {
            m_head->nextbaixo = currentRow->nextbaixo;
        }

        if (prevCol != nullptr) {
            prevCol->nextdireita = currentRow->nextdireita;
        } else {
            m_head->nextdireita = currentRow->nextdireita;
        }

        delete currentRow;
    } else {
        std::cout << "Elemento nao encontrado." << std::endl;
    }
}


SparseMatrix SparseMatrix::copia() const {
    SparseMatrix copia(m_coluna, m_linha);

    Node* current = m_head->nextbaixo;
    while (current != nullptr) {
        copia.insert(current->linha, current->coluna, current->valor);
        current = current->nextbaixo;
    }

    return copia;
}
