#include "ListStack.h"
#include "ListQueue.h"
#include <crtdbg.h>
#include <string>
#include <fstream>

bool check_bracket_balance(std::string str) 
{
	auto check_brackets = [](char b1, char b2) {
		return b1 == '{' && b2 == '}' || b1 == '(' && b2 == ')' || b1 == '[' && b2 == ']';
	};
	bool result = true;
	Stack stack;
	size_t n = str.length();
	for (int i = 0; i < n && result; ++i) {
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
			stack.push(str[i]);
		else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
			if (stack.isEmpty())
				result = false;
			else if (!check_brackets(stack.get_top(), str[i]))
				result = false;
			else 
				stack.pop();
		}
	}
	return result && stack.isEmpty();
}

bool print_all_childs(int ** matrix, int size, int humanI)
{
	bool isHaveChilds = false;
	Queue qu;
	for (int i = 0; i < size; ++i) // сначала закладываем всех прямых потомков в очередь
		if (matrix[humanI][i]) {
			isHaveChilds = true;
			qu.push(i);
		}
	while (!qu.isEmpty()) { // если прямые потомки есть то выводим их индексы добавляем их прямых потомков
		int index = qu.get_head();
		qu.pop();
		std::cout << index << ' ';
		for (int i = 0; i < size; ++i)
			if (matrix[index][i])
				qu.push(i);
	}
	return isHaveChilds;
}

int main()
{
	std::ifstream file("family_tree.txt");
	if (file) {
		int n;
		file >> n;
		int** matrix = new int* [n];
		for (int i = 0; i < n; ++i)
			matrix[i] = new int[n];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				file >> matrix[i][j];
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';


		if (!print_all_childs(matrix, n, 2)) 
			std::cout << "Don't have childs!\n";

		for (int i = 0; i < n; ++i)
			delete[] matrix[i];
		delete[] matrix;
	}
	std::cin.get();
	_CrtDumpMemoryLeaks();
}