#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

template<typename ...Ts>
auto num = sizeof...(Ts);

int main()
{
	num<int, float>;

	print_ << num<int, int, char> << '\n';
 

	std::cin.get();
	return 0;
}