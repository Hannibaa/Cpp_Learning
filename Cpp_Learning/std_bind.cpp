#include <iostream>
#include <functional>

#include "MyLib/Console_Library/escape_code.h"


void F(int x, int y, int& sum) {
	print_ << "_1 " << x << "    _2 " << y << end_;

	sum = x + y;
}


int main()
{
	int sum;
	auto f = std::bind(F, std::placeholders::_2, std::placeholders::_1, 100);
	auto g = std::bind(F, 1000, std::placeholders::_1, 0);

	F(3, 6, sum);
	f(3, 6);
	g(23);

	std::cin.get();
	return 0;
}