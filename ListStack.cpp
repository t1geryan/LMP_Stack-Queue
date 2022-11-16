#include "ListStack.h"

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	while (top) {
		pop();
	}
}

bool Stack::isEmpty()
{
	return !top;
}

void Stack::push(TInfo elem)
{
	ptrNode p = new Node(elem, top);
	top = p;
}

void Stack::pop()
{
	ptrNode p = top;
	top = top->next;
	delete p;
}

TInfo Stack::get_top()
{
	return top->getInfo();
}

void Stack::print()
{
	ptrNode p = top;
	while (p) {
		std::cout << p->getInfo() << ' ';
		p = p->next;
	}
	std::cout << '\n';
}
