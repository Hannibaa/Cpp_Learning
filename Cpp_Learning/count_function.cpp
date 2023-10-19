#include <iostream>
#include <algorithm>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <MyLib/random_vector.h>
#include <MyLib/vector_utility1.h>




int main()
{
	std::string TF[2] = { "False", "True" };

	Print_(color::Red, "Testing count() function : ") << end_;

	auto vec = vu::makeRandomContainer<std::vector, int>(0, 100, 200);

	print_ << COLOR(color::Red, "The vector is ") << end_;

	vu::print_container(vec);
	newline_;
	int value = 4;
	print_ << "how much in vec equal to " << value << " : " <<
		std::count(vec.begin(), vec.end(), value) << end_;
	value = 16;
	print_ << "how much in vec satisfaye square equl to " << value << " : " <<
		std::count_if(vec.begin(), vec.end(), [&value](int x)->bool {return x * x == value; }) << end_;


	// Using for string manipulation:

	std::string text = "hello; how are you? is there! one here.";
	Print_(color::Aqua, text) << end_;
	char c = 'h';
	print_ << "how much we have " << c << " : " <<
		std::count(text.begin(), text.end(), c) << end_;

	wait_;
	return 0;
}