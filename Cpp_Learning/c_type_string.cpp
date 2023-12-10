#include <iostream>

#define _SIZEOF(Array)        (sizeof(Array)/sizeof(Array[0]))

int main()
{
	const char* _FT[]{ "False","True", "UB"};

	const char* str{ "hello" };

	const char str2[]{ "hello" };

	std::cout << "size of " << _SIZEOF(_FT) << '\n';
	std::cout << "size of " << _SIZEOF(str) << '\n';
	std::cout << "size of " << _SIZEOF(str2) << '\n';

	std::cout << "is true or false " << _FT[2300 > 555] << '\n';



	std::cin.get();
	return 0;
}