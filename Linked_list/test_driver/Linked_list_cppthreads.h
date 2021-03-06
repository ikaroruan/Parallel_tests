// File: Linked_list_cppthreads.h
// Author: Ikaro Costa
// Date: 11/13/2016
// Header file for a Doubly linked list to be parallelized in the future.

#ifndef LINKED_LIST_CPPTHREADS_H
#define LINKED_LIST_CPPTHREADS_H

#define NUMBER_OF_THREADS 4

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include "List_node.h"

template<typename T>
class Linked_list_cppthreads
{
	public:

	// Constructor and Destructor.
	Linked_list_cppthreads();
	~Linked_list_cppthreads();

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
	List_node<T>* find_parallel(T value, List_node<T>* start, List_node<T>* end);
	List_node<T>* find(List_node<T>* node);

	// PRE: Value or node to be checked if it is on the list.
	// POST: Uses find member function to check if it is on the list.
	// RETURN: False if find function return nullptr, and true otherwise.
	bool is_element(List_node<T>* node);
	bool is_element(T value);

	void update_info();

	// Access the member variables.
	int size();
	List_node<T>* front();
	List_node<T>* back();
	List_node<T>* index(int pos);
	void print();

	double time_parallel = 0;
	double time_traversing = 0;
	
	private:
	int _size;
	List_node<T>* _front;
	List_node<T>* _back;
	int* _thread_size;
	std::mutex m;
	List_node<T>** _tbegin;
	int _rebalance_factor;
	
	// Modifiers for the member variables.
	void size(int num);
	void front(List_node<T>* node);
	void back(List_node<T>* node);
};

#include "Linked_list_cppthreads.hpp"

#endif // LINKED_LIST_CPPTHREADS_H
