#ifndef List_h
#define List_h

#include <iostream>
#include <stdexcept>

struct Node 
{
    int value;
    Node *prev;
    Node *next;

    Node(const int& val, Node *prevPtr, Node *nextPtr)
    {
        value = val;
        prev = prevPtr;
        next = nextPtr;
    }

    ~Node() {
        std::cout << "removido: " << value << std::endl;
    }
};

class List {
private:
    Node *m_head;
    size_t m_size;

public:
    class iterator {
    private:
        Node *pointer;
    public:
        iterator() {
            pointer = nullptr;
        }
        iterator(const iterator& it) {
            pointer = it.pointer;
        }
        iterator(Node *ptr) {
            pointer = ptr;
        }
        bool operator!=(const iterator& it) {
            return this->pointer != it.pointer;
        }
        bool operator==(const iterator& it) {
            return this->pointer == it.pointer;
        }
        int& operator*() {
            return pointer->value;
        }
        iterator operator++() {
            pointer = pointer->next;
            return *this;
        }
        iterator operator++(int) {
            iterator it_old(pointer);
            pointer = pointer->next;
            return it_old;
        }
        iterator operator=(const iterator& it) {
            pointer = it.pointer;
            return *this;
        }
    };

    iterator begin() {
        return iterator(m_head->next);
    }

    iterator end() {
        return iterator(m_head);
    }

    List() {
        m_head = new Node(0, nullptr, nullptr);
        m_head->next = m_head;
        m_head->prev = m_head;
        m_size = 0;
    }

    List(const List& lst) {
        m_head = new Node(0, nullptr, nullptr);
        m_head->next = m_head;
        m_head->prev = m_head;
        Node *aux = lst.m_head->next;
        Node *auxMain = m_head;
        while (aux != lst.m_head) {
            Node *newNode = new Node(aux->value, auxMain, m_head);
            auxMain->next = newNode;
            auxMain = auxMain->next;
            aux = aux->next;
        }
        m_head->prev = auxMain;
        m_size = lst.m_size;
    }

    void push_back(const int& v) {
        Node *aux = new Node(v, m_head->prev, m_head);
        aux->prev->next = aux;
        m_head->prev = aux;
        m_size++;
    }

    void push_front(const int& v) {
        Node *aux = new Node(v, m_head, m_head->next);
        m_head->next->prev = aux;
        m_head->next = aux;
        m_size++;
    }

    void pop_back() {
        if (m_size != 0) {
            Node *aux = m_head->prev;
            aux->prev->next = m_head;
            m_head->prev = aux->prev;
            delete aux;
            m_size--;
        }
    }
    //chamada para o insertionsort
    void insertionsort(int A[], int inicio, int fim);
    //chamada para a bubblesort
    void bubblesort(int A[], int inicio, int fim);
    //chamada para a mergesort
    void mergesort(int A[],  int inicio, int fim);
    //funcao auxiliar para mergesort
    void merge(int A[], int inicio, int meio, int fim);
    //chamada para quicksort
    void quicksort(int A[], int inicio, int fim);
    //funcao auxiliar para quicksort
    int partition(int A[], int inicio, int fim);
};

#endif