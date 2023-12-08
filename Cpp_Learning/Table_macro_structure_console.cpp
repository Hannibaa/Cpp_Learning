#include <iostream>
#include "MyLib/Console_Library/tables.h"

#define printm_(x,y)   print_ << MOVETO(x,y)

std::string add_line(int x, int y, table::STYLE s, table::STYLE s_last) {
	std::stringstream ss;

	ss << UNDERLINE << _cell(std::to_string(x), s, right);
	ss << UNDERLINE << _cell(std::to_string(y), s_last, left);
	ss << end_;

	return ss.str();
}

int main()
{
	const char solid_left     = '\xdd';
	const char solid_right    = '\xde';
	const char solid_complete = '\xdb';
	const char solid_up       = '\xdf';
	const char solid_down     = '\xdc';
	const char solid_center   = '\xfe';

	table::STYLE s_title = table::make_style(color::Fuchsia, color::Grey15, 41, 
		table_vline, table_vline);
	table::STYLE s = table::make_style(color::Aqua, color::Grey23, 20, table_vline, 0);
	table::STYLE s_last = table::make_style(color::Aqua, color::Grey23, 20, table_vline, table_vline);
	

	

	std::string name1 = "editor";
	std::string name2 = "Names";

	//print_ << Cell_text(name1, s, left) << end_;
	print_ << UNDERLINE << _cell("            value of function ", s_title, left) << end_;
	print_ << UNDERLINE << _cell("coord x ", s, right); 
	print_ << UNDERLINE << _cell("coord y ", s_last, left);
	print_ << end_;

	for (int i = 0; i < 10; ++i) {
		print_ << table::add_line_table(i, s, 3*i , s_last);
	}

	print_ << SAVECURSORPOSITION;
	printm_(70, 1) << "New value x : "; int ii;
	std::cin >> ii;
	printm_(70, 2) << "New value y : "; int jj;
	std::cin >> jj;
	print_ << RESTORCUR_SAVED_POS;

	print_ << table::add_line_table(ii, s, jj, s_last);


	std::cin.get();
	return 0;
}