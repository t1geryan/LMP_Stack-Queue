#pragma once
#include <iostream>
// �������� ���������� ������� �� ���� ��������� ����������� �������
using TInfo = int;

class ArrayQueue
{
private:
	static const int maxCount = 100;
	TInfo elements[maxCount];
	int headI, tailI;
public:
	ArrayQueue();
	bool isEmpty();
	bool isFull();
	void push(TInfo elem);
	void pop();
	TInfo get_head();
	void print();
};

