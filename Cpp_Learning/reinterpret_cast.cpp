#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

/* Leila AlAtar */

volatile uint64_t& memory(const uint64_t location) {
	return *reinterpret_cast<uint64_t*>(location);
}


int main()
{
	uint64_t loc = 0xff00;

	Print_(color::Red, "adress is ") << memory(loc) << end_;
	Print_(color::Green, "read what we have at 0x7700 : ") << memory(loc) << end_;
   

	wait_;
	return 0;
}