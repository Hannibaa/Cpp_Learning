#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <vector>
#include <MyLib/random_vector.h>
#include <MyLib/vector_utility1.h>

/*
         testing of std::copy and insert member function in vector
		 we also try to construct by insertion of c-array.
*/

int main()
{
	auto vec = vu::makeRandomVector<int>(0, 100, 10);

	std::vector<int> one{ -1,-2,-3,-4 };

	vu::print_container(vec.begin(), vec.end());

	//vec.insert(vec.begin()+5, one.begin(), one.end());

	std::copy(one.begin()+1, one.end(), vec.begin()+2);
	newline_;
	Print_(color::Green, "vector of integer : ") << end_;
	vu::print_container(vec.begin(), vec.end());

	wait_;
	cls();

	Print_(color::Green, "Now testing inserting function ");
	std::vector<int> vv{ 0,1,2,3,4,5,6,7,8,9 };

	vu::print_container(vv, "vector vv :"); newline_;

	vv.insert(vv.begin() + 4, { -1,-2,-3 });
	print_ << "new size " << vv.size() << end_;
	vu::print_container(vv, "vector after insertion vv :"); newline_;

	// insert at end

	vv.insert(vv.end(), {-4,-5,-6});
	print_ << "new size " << vv.size() << end_;
	vu::print_container(vv, "vector insert at end vv :"); newline_;

	cls();

	// Insert C - Array to vector . it work

	Print_(color::Green, "trying to insert C-array by construction of vector") << end_;

	int* pint = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::vector<int> v_int(pint,pint+9);

	vu::print_container(v_int, "vector int : ");

	// using insert function on C array 

	v_int.insert(v_int.end(), pint, pint + 5);

	vu::print_container(v_int, "vector int after insert : ");

	std::cin.get();
	return 0;
}