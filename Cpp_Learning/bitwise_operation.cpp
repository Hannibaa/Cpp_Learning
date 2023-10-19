#include <iostream>
#include <bit>
#include <set>
#include <bitset>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/bit_utility.h"

/* count significative Zero in binary representation  
    std::_Countr_zero_tzcnt<T>(i)                           */


using color = ESC::Color256;

struct Point { float x, y; };

int main()
{
	int i = 1;
	double d = 3.4343434e+10;

	Point point{2.55f,5.5f};

	std::bitset<32> bit_i(i);
	std::bitset<64> bit_d(d);
	//std::bitset<64> bit_point(point);
    
	Print_(color::Red, bit_i) << end_;
	Print_(color::Green, std::_Countr_zero_tzcnt(i)) << end_;

	Print_(color::Red, bit_d) << end_;
	Print_(color::Green, std::_Countr_zero_tzcnt(d)) << end_;

	Print_(color::Red, bit_d) << end_;
	Print_(color::Green, std::_Countr_zero_tzcnt(d)) << end_;


	wait_;
	return 0;
}