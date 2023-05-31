#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include "Node.h"

template <typename T>
class Stack
{
private:
    Node<T> *m_top;
    int m_size;


public:
    Stack();
    {
        m_top = nullptr;
        m_size = 0;
    }
    bool empty()
    {
        return m_top == nullptr;
    }

    int size()
    {
        return m_size;
    } 

    T& top()
    {
        if(empty())
        {
            throw std::out_of_range("Stack underflow");
        }
        return m_top->value;
    }

    void push(const T& val)
    {
        Node<T> *aux = new Node(val, m_top);
        m_top = aux;
        m_size++;
    }

    void pop()
    {
        if(m_size != 0)
        {
            Node<T> *aux = m_top;
            m_top = m_top->next;
            aux->next = nullptr;
            delete aux;
            m_size--;
        }
    }

    ~Stack()
    {
        delete m_top;
    }
};


#endif