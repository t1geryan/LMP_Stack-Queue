#include "RingArrayQueue.h"

RingArrayQueue::RingArrayQueue()
{
	headI = 0;
	tailI = -1;
}

bool RingArrayQueue::isEmpty()
{
	return tailI == -1;
}

bool RingArrayQueue::isFull()
{
	if (!isEmpty())
		return (tailI - headI + maxCount) % maxCount + 1 == maxCount;
	else
		return false;
}

void RingArrayQueue::push(TInfo elem)
{
	tailI = (tailI + 1) % maxCount;
	elements[tailI] = elem;
}

void RingArrayQueue::pop()
{
	if (headI == tailI)
	{
		headI = 0;
		tailI = -1;
	}
	else
		headI = (headI + 1) % maxCount;
}

TInfo RingArrayQueue::get_head()
{
	return elements[headI];
}

void RingArrayQueue::print()
{
	for (int i = headI; i != tailI; i = (i + 1) % maxCount)
		std::cout << elements[i] << ' ';
	std::cout << elements[tailI] << '\n';
}
