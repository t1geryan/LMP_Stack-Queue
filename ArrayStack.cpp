#include "ArrayStack.h"

StackArray::StackArray() : topI(-1) {}

bool StackArray::isEmpty()
{
	return topI == -1;
}

bool StackArray::isFull()
{
	return topI == maxCount - 1;
}

void StackArray::push(TInfo elem)
{
	if (!isFull())
		elements[++topI] = elem;
}

void StackArray::pop()
{
	--topI;
}

TInfo StackArray::get_top()
{
	return elements[topI];
}

void StackArray::print()
{
	for (int i = topI; i >= 0; --i)
		std::cout << elements[i] << ' ';
	std::cout << '\n';
}
