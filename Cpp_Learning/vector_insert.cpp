#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <vector>
#include <MyLib/random_vector.h>
#include <MyLib/vector_utility1.h>

/*
         testing of insert member function in vector
*/

int main()
{
	auto vec = vu::makeRandomVector<int>(0, 100, 10);

	std::vector<int> one{ -1,-2,-3,-4 };

	vu::print_container(vec.begin(), vec.end());

	//vec.insert(vec.begin()+5, one.begin(), one.end());

	std::copy(one.begin()+1, one.end(), vec.begin()+2);

	Print_(color::Green, "vector of integer : ") << end_;
	vu::print_container(vec.begin(), vec.end());


	std::cin.get();
	return 0;
}