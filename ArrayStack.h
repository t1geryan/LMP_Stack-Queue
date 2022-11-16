#pragma once
#include <iostream>
// Сплошная реализация стека на базе одномерного массива
using TInfo = int;

class StackArray
{
private:
	static const int maxCount = 100;
	TInfo elements[maxCount];
    int topI;
public:
	StackArray();
	bool isEmpty();
	bool isFull();
	void push(TInfo elem);
	void pop();
	TInfo get_top();
	void print();
};


