/**
 * @file List.h
 * @author Elysson & Gustavo
 * @brief 
 * @version 0.1
 * @date 2023-07-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LIST_H
#define LIST_H

#include <ostream>

struct Node
{
	int value;
	Node* prev;
	Node* next;

	Node(const int value, Node* prev, Node* next) {
		this->prev = prev;
		this->value = value;
		this->next = next;
	}
};

class List
{
private:
	int tamanho = 0 ;
	Node* m_head = nullptr ;
	Node* m_tail = nullptr ;
	// método auxiliar interno da classe
	Node* partition(Node* start, Node* end) const;
public:
	List();
	List(const List& lst);

	bool empty() const;
	int size() const;
	void push_back(const int& value);
	void push_front(const int& value);
	void pop_back();
	void pop_front();
	void clear();
    void print() const;

	void quick_sort_util(Node* start, Node* end) const;
	void bubble_sort() const;
	void insertion_sort() const;
	void selection_sort() const;
	void merge_sort() const;
	void quick_sort() const;
	void shaker_sort() const;

	~List();
};

#endif //LIST_H
