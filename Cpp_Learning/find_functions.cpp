#include <iostream>
#include <algorithm>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <MyLib/random_vector.h>
#include <MyLib/vector_utility1.h>
#include <MyLib/stringfunctionhelper.h>


int main()
{
	std::string TF[2] = { "False", "True" };

	Print_(color::Red, "Testing count() function : ") << end_;

	auto vec = vu::makeRandomContainer<std::vector, int>(0, 100, 100);

	print_ << COLOR(color::Red, "The vector is ") << end_;

	vu::print_container(vec);
	newline_;
	int value = 46;
	auto result = std::find(vec.begin(), vec.end() , value);

	if (result != vec.end())
		print_ << "find a value " << value << " : " << *result << end_; else print_ << "not found\n";



	wait_;

	return 0;
}