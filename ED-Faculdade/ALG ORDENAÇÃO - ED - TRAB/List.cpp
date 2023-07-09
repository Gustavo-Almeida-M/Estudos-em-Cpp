/**
 * @file List.cpp
 * @author Elysson & Gustavo
 * @brief 
 * @version 0.1
 * @date 2023-07-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "List.h"

#include <functional>
using std::function;

#include <iostream>
using std::swap;

List::List()
{
    this->m_head = new Node(0, nullptr, nullptr);
    this->m_tail = new Node(0, nullptr, nullptr);
}

List::List(const List &lst)
{
    clear();
    Node *viajante = lst.m_head->next;
    while (viajante)
    {
        push_back(viajante->value);
        viajante = viajante->next;
    }
}

bool List::empty() const
{
    return tamanho == 0;
}

int List::size() const
{
    return tamanho;
}

void List::push_back(const int &value)
{
    const auto new_Node = new Node(value, nullptr, nullptr);
    if (tamanho == 0)
    {
        m_head->next = new_Node;
        m_tail->prev = new_Node;
    }
    else
    {
        Node *temp = m_tail->prev;
        new_Node->prev = temp;
        temp->next = new_Node;
        m_tail->prev = new_Node;
    }
    tamanho++;
}

void List::push_front(const int &value)
{
    const auto new_Node = new Node(value, nullptr, nullptr);
    if (tamanho == 0)
    {
        m_head->next = new_Node;
        m_tail->prev = new_Node;
    }
    else
    {
        Node *temp = m_head->next;
        new_Node->next = temp;
        temp->prev = new_Node;
        m_head->next = new_Node;
    }
    tamanho++;
}

void List::pop_back()
{
    const Node *temp = m_tail->prev;
    m_tail->prev = temp->prev;
    m_tail->prev->next = nullptr;
    delete temp;
    if (tamanho == 1)
    {
        m_head->next = nullptr;
    }
    tamanho--;
}

void List::pop_front()
{
    const Node *temp = m_head->next;
    m_head->next = temp->next;
    m_head->next->prev = nullptr;
    delete temp;
    if (tamanho == 1)
    {
        m_tail->prev = nullptr;
    }
    tamanho--;
}

void List::clear()
{
    Node *viajante = m_head->next;
    while (viajante)
    {
        const Node *lixo = viajante;
        viajante = viajante->next;
        delete lixo;
    }
    m_head->next = nullptr;
    m_tail->prev = nullptr;
    tamanho = 0;
}

void List::bubble_sort() const
{
    if (this->tamanho < 2)
    {
        return;
    }

    for (Node *viajante_a = m_head->next; viajante_a; viajante_a = viajante_a->next)
    {
        for (Node *viajante_b = viajante_a->next; viajante_b; viajante_b = viajante_b->next)
        {
            if (viajante_a->value > viajante_b->value)
            {
                swap(viajante_a->value, viajante_b->value);
            }
        }
    }
}

void List::quick_sort_util(Node *start, Node *end) const
{
    if (end != nullptr && start != end && start != end->next)
    {
        Node *pivot = partition(start, end);
        quick_sort_util(start, pivot->prev);
        quick_sort_util(pivot->next, end);
    }
}

void List::quick_sort() const
{
    if (tamanho < 2)
    {
        return;
    }

    quick_sort_util(m_head->next, m_tail->prev);
}

void List::insertion_sort() const
{
    if (tamanho < 2)
    {
        return;
    }

    Node *viajante_a = m_head->next->next;
    while (viajante_a)
    {
        const int value = viajante_a->value;
        Node *viajante_b = viajante_a->prev;
        while (viajante_b && viajante_b->value > value)
        {
            viajante_b->next->value = viajante_b->value;
            viajante_b = viajante_b->prev;
        }
        viajante_b ? viajante_b->next->value = value : m_head->next->value = value;
        viajante_a = viajante_a->next;
    }
}

void List::selection_sort() const
{
    if (tamanho < 2)
    {
        return;
    }

    Node *viajante_a = m_head->next;
    while (viajante_a)
    {
        Node *min = viajante_a;

        Node *viajante_b = viajante_a->next;
        while (viajante_b)
        {
            if (viajante_b->value < min->value)
            {
                min = viajante_b;
            }
            viajante_b = viajante_b->next;
        }
        swap(viajante_a->value, min->value);
        viajante_a = viajante_a->next;
    }
}

void List::merge_sort() const
{
    if (tamanho < 2)
    {
        return;
    }

    List left_half;
    List right_half;

    const int half = tamanho / 2;

    Node *viajante = m_head->next;
    for (int i = 0; i < half; i++)
    {
        left_half.push_back(viajante->value);
        viajante = viajante->next;
    }
    while (viajante)
    {
        right_half.push_back(viajante->value);
        viajante = viajante->next;
    }

    left_half.merge_sort();
    right_half.merge_sort();

    Node *viajante_l = left_half.m_head->next;
    Node *viajante_r = right_half.m_head->next;
    viajante = m_head->next;

    while (viajante_l && viajante_r)
    {
        if (viajante_l->value <= viajante_r->value)
        {
            viajante->value = viajante_l->value;
            viajante_l = viajante_l->next;
        }
        else
        {
            viajante->value = viajante_r->value;
            viajante_r = viajante_r->next;
        }
        viajante = viajante->next;
    }

    while (viajante_l)
    {
        viajante->value = viajante_l->value;
        viajante_l = viajante_l->next;
        viajante = viajante->next;
    }

    while (viajante_r)
    {
        viajante->value = viajante_r->value;
        viajante_r = viajante_r->next;
        viajante = viajante->next;
    }
}

Node *List::partition(Node *start, Node *end) const
{
    int pivot = end->value;
    Node *i = start->prev;

    for (Node *j = start; j != end; j = j->next)
    {
        if (j->value <= pivot)
        {
            i = (i == nullptr) ? start : i->next;
            swap(i->value, j->value); 
        }
    }

    i = (i == nullptr) ? start : i->next;
    swap(i->value, end->value);
    return i;
}

void List::shaker_sort() const
{
    if (this->tamanho < 2)
    {
        return;
    }

    bool swapped = true;
    Node *start = m_head->next;
    Node *end = m_tail->prev;

    while (swapped)
    {
        swapped = false;

        // Passo da esquerda para a direita
        Node *viajante = start;
        while (viajante != end)
        {
            if (viajante->value > viajante->next->value)
            {
                swap(viajante->value, viajante->next->value);
                swapped = true;
            }
            viajante = viajante->next;
        }

        // Se nenhum elemento foi trocado, a lista já está ordenada
        if (!swapped)
        {
            break;
        }

        // Atualiza o ponteiro do fim
        end = end->prev;

        // Passo da direita para a esquerda
        viajante = end;
        while (viajante != start)
        {
            if (viajante->value < viajante->prev->value)
            {
                swap(viajante->value, viajante->prev->value);
                swapped = true;
            }
            viajante = viajante->prev;
        }

        // Atualiza o ponteiro do início
        start = start->next;
    }
}


/*
void List::print() const
{
    Node *viajante = m_head->next;
    while (viajante)
    {
        std::cout << viajante->value << " ";
        viajante = viajante->next;
    }
    std::cout << std::endl;
}
*/
List::~List()
{
    clear();
    delete m_head;
    delete m_tail;
}
