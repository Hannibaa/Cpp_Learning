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
	std::vector vInt{ 1,3,4,5,6,7,5 };

	// position + size 
	std::vector vInt1(vInt.begin()+1, vInt.begin()+4);

	vu::print_container(vInt);
	vu::print_container(vInt1);


	std::cin.get();
	return 0;
}