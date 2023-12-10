#include <iostream>
#include "MyLib/Console_Library/tables.h"

#define printm_(x,y)   print_ << MOVETO(x,y)



int main()
{

	// declare style of table
	table::STYLE s_title = table::make_style(color::Fuchsia, color::Grey15, 41, 
		table_vline, table_vline);
	table::STYLE s = table::make_style(color::Aqua, color::Grey23, 20, table_vline, 0);
	table::STYLE s_last = table::make_style(color::Aqua, color::Grey23, 20, 
		table_vline, table_vline);
	

	

	//print_ << Cell_text(name1, s, left) << end_;
	print_ << UNDERLINE << _cell("            value of function ", s_title, left) << end_;
	print_ << UNDERLINE << _cell("coord x ", s, right); 
	print_ << UNDERLINE << _cell("coord y ", s_last, left);
	print_ << end_;

	for (int i = 0; i < 10; ++i) {
		print_ << table::add_line_table(i, s, 3*i , s_last);
	}


	print_ << table::add_line_table(ii, s, jj, s_last);


	std::cin.get();
	return 0;
}