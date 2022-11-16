#include "ListStack.h"
#include <crtdbg.h>
#include <string>


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

int main()
{
	std::cout << check_bracket_balance("(a+[c*{a+b}+d]-2)");
	std::cin.get();
	_CrtDumpMemoryLeaks();
}