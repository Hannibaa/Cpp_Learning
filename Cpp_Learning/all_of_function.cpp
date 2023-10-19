#include <iostream>
#include <algorithm>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <MyLib/random_vector.h>
#include <MyLib/vector_utility1.h>




int main()
{
	std::string TF[2] = { "False", "True" };

	Print_(color::Green, "testing of all_of, any_of, none_of from algrithm standard library") << end_;

	auto vec = vu::makeRandomContainer<std::vector, int>(0, 100, 150);

	print_ << COLOR(color::Red, "The vector is ") << end_;

	vu::print_container(vec);
	newline_;
	int value = 99;
	print_ << "check if vector all inferieur of 99  " << TF[std::all_of(vec.begin(), vec.end(),
		[&value](int x)->bool {return x < value; })] << end_;
	value = 50;
	print_ << "check if vector all inferieur of 50  " << TF[std::all_of(vec.begin(), vec.end(),
		[&value](int x)->bool {return x < value; })] << end_;
	value = 10;
	print_ << "check if vector all inferieur of 10  " << TF[std::all_of(vec.begin(), vec.end(),
		[&value](int x)->bool {return x < value; })] << end_;
	newline_;

	Print_(color::Green, "test any_of function") << end_;
	value = 1;
	print_ << "std::any_of : " << end_;
	print_ << "is there at least one element equal to " << value << " : " << TF[std::any_of(vec.begin(), vec.end(),
		[&value](int x)->bool {return x == value; })] << end_;

	value = 33;
	print_ << "std::none_of : " << end_;
	print_ << "none at least of element equal to " << value << " : " << TF[std::none_of(vec.begin(), vec.end(),
		[&value](int x)->bool {return x == value; })] << end_;





	wait_;
	return 0;
}