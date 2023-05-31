#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
#include "Node.h"

/**
 * Classe que implementa uma fila (FIFO - first in, first out)
*/
template <typename T>
class Queue {
private:
    Node<T>* m_head;  // ponteiro para primeiro elemento
    Node<T>* m_tail;  // ponteiro para ultimo elemento
    int m_size;       // numero de elementos na fila

public:
    // Construtor default: cria fila vazia
    Queue();
    // Insere elemento na fila
    void push(const T& v);
    // Remove um elemento da fila
    void pop();
    // Retorna se fila esta vazia
    bool empty();
    // Acessa o primeiro elemento da fila.
    // Se fila estiver vazia, lance uma out_of_range exception
    T& front();
    // Acessa o ultimo elemento da fila.
    // Se fila estiver vazia, lance uma out_of_range exception
    T& back();
    // Retorna o numero de elementos na fila
    int size();
    // Construtor de copia
    Queue(const Queue& q);
    // sobrecarga do operador de atribuicao
    Queue& operator=(const Queue& q);
    // sobrecarga do operador ==
    bool operator==(const Queue& q) const;
};

template <typename T>
Queue<T>::Queue() {
    m_head = m_tail = nullptr;
    m_size = 0;
}

template <typename T>
void Queue<T>::push(const T& v) {
    Node<T> *aux = new Node<T>(v, nullptr);
    if( m_size == 0 ) {
        m_head = m_tail = aux;
    }
    else {
        m_tail->next = aux;
        m_tail = aux;
    }
    m_size++;
}
template <typename T>
void Queue<T>::pop() {
    // zero elementos
    if(m_size == 0) 
        return;
    // temos pelo menos um elemento!!
    Node<T> *aux = m_head;
    m_head = m_head->next;
    aux->next = nullptr;
    delete aux;
    m_size--;
    if(m_head == nullptr) {
        m_tail = nullptr;
    }
}

template <typename T>
int Queue<T>::size() {
    return m_size;
}

template <typename T>
bool Queue<T>::empty() {
    return m_size == 0;
}

template <typename T>
T& Queue<T>::front() {
    if(m_size == 0)
        throw std::out_of_range("fila vazia");
    else {
        return m_head->value;
    }
}

template <typename T>
bool Queue<T>::operator==(const Queue& q) const
{
    if(m_size != q.m_size)
    {
        return false;
    }

}

#endif