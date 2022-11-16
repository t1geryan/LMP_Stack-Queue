#pragma once
#include <iostream>
// Цепочная реализация очереди на базе односвязного списка
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

class Queue
{
private:
	ptrNode head, tail;
public:
	Queue();
	~Queue();
	bool isEmpty();
	void push(TInfo elem);
	void pop();
	TInfo get_head();
	void print();
};

