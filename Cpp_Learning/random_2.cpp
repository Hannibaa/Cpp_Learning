#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/random_generator.h"

/*
         test now Random device like . copyable. and assignable.
*/

int main()
{
	RNG::Random rd;
	std::random_device rd2;

	std::mt19937 gen(rd());
	std::mt19937 gen2(rd2());

	std::uniform_int_distribution<int> x(-10, 10);
	std::uniform_int_distribution<int> x2(-10, 10);

	for (int i = 0; i < 10; ++i) {
		print_ << "x  : " << x(gen) << end_;
		print_ << "x2 : " << x2(gen) << end_;
		newline_;
	}


	std::cin.get();
	return 0;
}