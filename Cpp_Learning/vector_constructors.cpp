#include <iostream>
#include <vector>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <MyLib/vector_utility1.h>

/* 
                        ++++++++++++++++++++++++++++++++++++++++++
						+	Test of constructor of std::vector.  +
						++++++++++++++++++++++++++++++++++++++++++
*/

int main()
{
	// constructor initial_list
	std::vector vInt{ 1,3,4,5,6,7,5 };

	// constructor 
	std::vector vInt1(vInt.begin()+1, vInt.begin()+4);

	// constructor difference between () and {};
	std::vector<int>  vInt2(10, 200);
	std::vector<int> vInt3{ 10,200 };
	std::vector<int> vInt4(10);
	std::vector<int> vInt5{ 10 };



	vu::print_container(vInt);
	vu::print_container(vInt1);
	vu::print_container(vInt2);
	vu::print_container(vInt3);
	vu::print_container(vInt4);
	vu::print_container(vInt5);


	std::cin.get();
	return 0;
}