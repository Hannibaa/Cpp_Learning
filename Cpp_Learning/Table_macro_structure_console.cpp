#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

#define bg_color(i)      "\x1b[48;5;"#i"m" 
#define fg_color(i)      "\x1b[38;5;"#i"m"

struct TITLE {
	std::string _name;
	std::string _fgcolor;
	std::string _bgcolor;
	int         _width;
	char        _sep0;
	char        _sep1;

	TITLE() = default;
	TITLE(const std::string_view name, int fg, int bg, int width, char s0 , char s1 ='|')
		: _name{ name }
		, _fgcolor{ std::string(fg_color(fg)) }
		, _bgcolor{ std::string(bg_color(bg)) }
		, _width{ width }
		, _sep0{ s0 }
		, _sep1{ s1 }
	{}

	TITLE(const std::string_view name, int fg, int bg, int width )
		: _name{name}
		, _fgcolor{fg_color(fg)}
		, _bgcolor(bg_color(bg))
		, _width{width}
		, _sep0{'|'}
		, _sep1{'|'}
	{}
};

#define TitleConstructor(T,name, bg, fg, width, sep0 , sep1 )     	TITLE T; \
                                        T._bgcolor = bg_color(bg);			 \
                                        T._fgcolor = fg_color(fg);			 \
                                        T._name = #name;					 \
                                        T._width = width;					 \
                                        T._sep0 = sep0;						 \
                                        T._sep1 = sep1;						 \


#define _cell(t,right_left)     t._sep0 << t._fgcolor << t._bgcolor << std::setw(t._width)   \
                                       << std::right_left << t._name << RESETMODE << t._sep1 \

int main()
{
	print_ << std::setw(10) << std::right << "helllo " << end_;

	TITLE t1;
	t1._bgcolor = bg_color(5);
	t1._fgcolor = fg_color(9);
	t1._name = "function";
	t1._width = 15;
	t1._sep0 = '|';
	t1._sep1 = '|';

	TITLE t2( "    Number" , 12, 234, 30 , (char)0 , '|' );
	TITLE t3;
	t3._bgcolor = bg_color(236);
	t3._fgcolor = fg_color(12);
	t3._name = "  ROP ";
	t3._width = 15;
	t3._sep0 = '|';
	t3._sep1 = '|';

	TitleConstructor(t4, WOB, 239, 3, 10,'|','|')

	print_ << _cell(t1, left) << _cell(t1,right) << _cell(t4,right) 
		   << _cell(t3, left) <<  end_;



	std::cin.get();
	return 0;
}