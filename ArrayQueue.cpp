#include "ArrayQueue.h"

ArrayQueue::ArrayQueue(): headI(0), tailI(-1){}

bool ArrayQueue::isEmpty()
{
	return tailI == -1;
}

bool ArrayQueue::isFull()
{
	return tailI - headI == maxCount - 1;
}

void ArrayQueue::push(TInfo elem)
{
	if (tailI == maxCount - 1)// очередь у правого края - сдвиг влево
	{
		for (int i = headI; i <= tailI; ++i)
			elements[i - headI] = elements[i];
		tailI = tailI - headI;
		headI = 0;
	}
	elements[++tailI] = elem;
}

void ArrayQueue::pop()
{
	TInfo elem = elements[headI];
	if (headI == tailI)
	{
		headI = 0;
		tailI = -1;
	}
	else
		++headI;
}

TInfo ArrayQueue::get_head()
{
	return elements[headI];
}

void ArrayQueue::print()
{
	for (int i = headI; i <= tailI; ++i)
		std::cout << elements[i] << ' ';
	std::cout << '\n';
}

