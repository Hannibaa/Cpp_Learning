#include <iostream>
#include "MyLib/Console_Library/tables.h"






int main() {
	// making style:
	auto stitle = table::make_style(color::Yellow, color::Grey39, 15, table_vline, table_vline);

	table::MTable<int, float, char>  table(10, 10, "Drilling Parameters", stitle);




	wait_;
	return 0;
}





//int main()
//{
//	table::Table<int, float>  table(10, 10, "function plot");
//
//	std::vector<int> vi{ 1,3,4 };
//	std::vector<float> vf{ 3.4f,4.5f,6.6f };
//	
//
//	table.set_style(table::make_style(color::Yellow, color::Grey23, 15,
//		table_vline, table_vline));
//	table.set_style_cell(table::make_style(color::Yellow, color::Grey23, 15,
//		table_vline, table_vline));
//	table.set_style_head(table::make_style(color::Yellow, color::Grey19, 15,
//		table_vline, table_vline));
//	table.set_style_title(table::make_style(color::Yellow, color::Black, 15,
//		0, 0));
//	
//
//	table.add_line(21, 4.55f);
//	table.add_line(40, 5.66f);
//	table.add_lines(vi, vf);
//	table.set_titlesXY("incremental", "ROP ins");
//
//	table.draw();
//
//	std::cin.get();
//	return 0;
//}