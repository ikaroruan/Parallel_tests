// File:

#ifndef LIST_NODE_H
#define LIST_NODE_H

template<typename T>
class List_node
{
	public:
	
	// Constructor and Destructor
	List_node();
	~List_node();

	// PRE: Variable to be set.
	// POST: Set the member variable.
	// RETURN: None.
	void set_value(T value);
	void set_next(List_node<T>* next);
	void set_previous(List_node<T>* previous);

	// PRE: None.
	// POST: Gets the value of the member variable.
	// RETURN: The member variable value.
	T get_value();
	List_node<T>* get_next();
	List_node<T>* get_previous();

	private:
	// Private member variables.
	T _value;
	List_node<T>* _next;
	List_node<T>* _previous;

};

#include "List_node.hpp"

#endif // LIST_NODE_H
