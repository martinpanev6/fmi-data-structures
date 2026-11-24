#pragma once

#include <stdexcept>
#include <cassert>

template <typename T>
class LinkedStack {
public:
	LinkedStack();
	LinkedStack(const LinkedStack<T>& other);
	~LinkedStack();
	LinkedStack<T>& operator=(const LinkedStack<T>& other);

	void push(const T& elem);
	T pop();
	const T& top() const;
	bool isEmpty()const;
	bool isFull()const;

private:
	struct Node {
		T data;
		Node* next;

		Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
	} *tos;

	void clear();
	void copy(const Node* top);

	Node* spare = nullptr;
};

#include "Linked_Stack.inl"