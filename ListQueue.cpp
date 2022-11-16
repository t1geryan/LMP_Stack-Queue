#include "ListQueue.h"

Queue::Queue(): head(nullptr), tail(nullptr) {}

Queue::~Queue()
{
	while (head)
		pop();
}

bool Queue::isEmpty()
{
	return !head;
}

void Queue::push(TInfo elem)
{
	ptrNode p = new Node(elem, nullptr);
	if (isEmpty())
		head = p;
	else
		tail->next = p;
	tail = p;
}

void Queue::pop()
{
	ptrNode p = head;
	head = head->next; 
	delete p;
}

TInfo Queue::get_head()
{
	return head->getInfo();
}


void Queue::print()
{
	ptrNode p = head;
	while (p) {
		std::cout << p->getInfo() << ' ';
		p = p->next;
	}
	std::cout << '\n';
}
