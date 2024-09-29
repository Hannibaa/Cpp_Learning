#include <iostream>
#include "add.h"

#define  End '\n'



int main() {

	std::cout << "test multi file compilation " << End;

	std::cout << f(34) << End;
	//std::cout << add(2, 2) << End;

	std::cin.get();

	return 0;
}