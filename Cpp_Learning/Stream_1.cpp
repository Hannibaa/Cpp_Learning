#include <iostream>
#include <sstream>
#include <streambuf>
#include <thread>
#include <conio.h>
#include "MyLib/Console_Library/escape_code.h"

int _number_char{};


void menu() {
	print_ << SAVECURSORPOSITION;
	print_ << MOVETO(0,34)
		   << "CHAR[" << _number_char << "]"
		   << RESTORCUR_SAVED_POS;
}


int main()
{
	std::stringstream ss;
	int count{};
	char c{};

	while ( c = _getch() ) {
		
		++_number_char;
		ss << c;

		print_ << ss.str() << MOVETO(0,0);

		print_ << SAVECURSORPOSITION;
		print_ << MOVETO(0, 34)
			   << "CHAR[" << _number_char << "]"
			   << RESTORCUR_SAVED_POS;

		if (++count == 50) break;
	}

	print_ << "text size : " << ss.str().size() << end_;
	std::cout << "text{" << ss.str() << "}\n";

    std::cin.get();
	return 0;
}