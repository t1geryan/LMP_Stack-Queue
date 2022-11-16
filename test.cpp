#include "RingArrayQueue.h"
#include <crtdbg.h>

int main()
{
	if (1) {
		RingArrayQueue qu;
		for (int i = 1; i <= 10; ++i)
			qu.push(i);
		qu.print();
	}

	std::cin.get();
	_CrtDumpMemoryLeaks();
	
}