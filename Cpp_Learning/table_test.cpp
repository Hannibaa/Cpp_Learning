#include <iostream>
#include "MyLib/Console_Library/tables.h"



int main()
{
	table::Table<int, float>  table(10, 10, "function plot");

	

	table.set_style(table::make_style(color::Yellow, color::Grey23, 15,
		table_vline, table_vline));
	

	table.add_line(21, 4.55f);
	table.add_line(40, 5.66f);
	table.set_titlesXY("incremental", "ROP ins");

	table.draw();

	std::cin.get();
	return 0;
}