#include <iostream>
#include "MyLib/Console_Library/tables.h"



int main()
{
	table::Table<int, float>  table(10, 10, "function plot");

	table.add_line(21, 4.55f);
	table.add_line(40, 5.66f);

	table.draw();

	std::cin.get();
	return 0;
}