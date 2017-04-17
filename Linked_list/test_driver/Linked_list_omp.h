// File: Linked_list_omp.h
// Author: Ikaro Costa
// Date: 11/13/2016
// Header file for a Doubly linked list to be parallelized in the future.

#ifndef LINKED_LIST_OMP_H
#define LINKED_LIST_OMP_H

#include <iostream>
#include "List_node.h"
#include <omp.h>
#include <chrono>

template<typename T>
class Linked_list_omp
{
	public:

	// Constructor and Destructor.
	Linked_list_omp();
	~Linked_list_omp();

	// PRE: Gets an value of type T or a node List_node.
	// POST: Push values or elements on the linked list.
	// RETURN: none.
	void push_back(List_node<T>* node);
	void push_front(List_node<T>* node);
	void push_back(T value);
	void push_front(T value);
	void insert(std::vector<T>& v);

	// PRE: none.
	// POST: Pops nodes or elements from the list.
	// RETURN: none.
	void pop_back();
	void pop_front();

	// PRE: Node or value to be removed.
	// POST: Finds and remove the node or value from the list.
	// RETURN: none.
	void remove(List_node<T>* node);
	void remove(T value);

	// PRE: Value or node to be found on the list.
	// POST: Searches the node or value on the list.
	// RETURN: Returns the respective value or node it is on the list, and nullptr otherwise.
	List_node<T>* find(T value);
	List_node<T>* find(List_node<T>* node);

	// PRE: Value or node to be checked if it is on the list.
	// POST: Uses find member function to check if it is on the list.
	// RETURN: False if find function return nullptr, and true otherwise.
	bool is_element(List_node<T>* node);
	bool is_element(T value);

	void update_info();

	// Access the member variables.
	int size();
	List_node<T>* index(int pos);
	List_node<T>* front();
	List_node<T>* back();
	void print();
	double time_parallel();
	
	private:
	int _size;
	List_node<T>* _front;
	List_node<T>* _back;
	int _number_of_threads;
	int* _thread_size;
	List_node<T>** _tbegin;
	omp_lock_t m;
	int _rebalance_factor;
	double _time_parallel;
	
	// Modifiers for the member variables.
	void size(int num);
	void front(List_node<T>* node);
	void back(List_node<T>* node);
};

#include "Linked_list_omp.hpp"

#endif // LINKED_LIST_OMP_H