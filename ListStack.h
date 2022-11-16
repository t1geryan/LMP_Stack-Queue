#pragma once
#include <iostream>
// Цепочная реализация стека на базе односвязного списка
using TInfo = int;

struct Node
{
private:
	TInfo info;
public:
	Node* next;
	Node(TInfo info, Node* ptr = nullptr) :info(info), next(ptr) {}
	~Node()
	{
		next = nullptr;
	}
	TInfo getInfo() {
		return info;
	}
};

using ptrNode = Node*;

class Stack {
private:
	ptrNode top;
public:
	Stack();
	~Stack();
	bool isEmpty();
	void push(TInfo elem);
	void pop();
	TInfo get_top();
	void print();
};