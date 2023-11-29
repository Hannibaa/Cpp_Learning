/*
          These exemples taken from CppCon of Mr. Klaus.I. Type Erasure
		  Author : KADDA Aoues
*/

#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "Type_erasure_1.h"

void f(Command* command, int id) {
	(*command)(id);
	command->operator()(id);
}

int main()
{
	PrintCommand pc{};
	f(&pc, 9);
	SearchCommand sc{};
	f(&sc, 100000000);
	ExecuteCommand ec{};
	f(&ec, 100);

	std::cin.get();
	return 0;
}