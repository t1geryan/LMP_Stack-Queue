#pragma once
#include <iostream>
// �������� ���������� ������� �� ���� ���������� ����������� �������
using TInfo = int;

class RingArrayQueue
{
private:
	static const int maxCount = 100;
	TInfo elements[maxCount];
	int headI, tailI;
public:
	RingArrayQueue();
	bool isEmpty();
	bool isFull();
	void push(TInfo elem);
	void pop();
	TInfo get_head();
	void print();
};

