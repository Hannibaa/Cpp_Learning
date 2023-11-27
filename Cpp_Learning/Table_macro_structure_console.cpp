#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/Console_Library/tables.h"



int main()
{

	    CellCtor(t1, Depth, 240, 9, 15, '|', '|')

		CellCtor(t2, Number, 12, 234, 30, 0, '|')

		CellCtor(t3, ROP, 236, 12, 15, '|', '|')

		CellCtor(t4, WOB, 239, 3, 10, 0, 0)

		print_ << _cellr('|', bg_color(234), fg_color(22), 73, left,
			         "             Exemple table of drilling parameter", '|') << end_;

	print_ << UNDERLINE << _cell(t1, left) << UNDERLINE << _cell(t2,right) 
		   << UNDERLINE << _cell(t3, left) << UNDERLINE << _cell(t4,right) << end_;

	const char b = '|';

	for (int i = 0; i < 20; ++i) {
		print_ << UNDERLINE << _cellr(b, t1._fgcolor, t1._bgcolor, t1._width, left, i, '|') 
			   << UNDERLINE << _cellv(t2, left, i*i) 
			   << UNDERLINE << _cellv(t3, left, float(3.f*i/5.f))
			   << UNDERLINE << _cellv(t4, left, 5*i -2)
			   << end_;
	}


	std::cin.get();
	return 0;
}