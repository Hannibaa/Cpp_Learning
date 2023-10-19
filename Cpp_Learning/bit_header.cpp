#include <iostream>
#include <bitset>
#include <bit>
#include <set>

#include "MyLib/Console_Library/escape_code.h"

// C:\Users\Acer\source\Course C++\Cpp_Learning\Cpp_Learning

using namespace std;

// define a macro that get last char in any type
#define _FIRST_BYTE_SHORT(X)      ((char)(X & 0x00FF))
#define _SECOND_BYTE_SHORT(X)     ((char)(X & 0xFF00)>>8)

constexpr char _first_byte_short(short x) {
	return char(x & 0x00ff);
}

constexpr char _second_byte_short(short y) {
	return static_cast<char>(y >> 8);
}


int main() {



	short x = 0xabcd;  // here 0xabcd  is stored like ...|cd|ab|... -> 0xabcd.

	int i = 0xabcab00;
	std::bitset<32> bit_i(i);

	//// using defined macro
	//print_ << "first byte in short [" << std::hex << _FIRST_BYTE_SHORT(x) << "]\n";

	//// using defined function
	//print_ << "first byte in short [" << std::hex << _first_byte_short(x) << "]\n";

	//// extract second byte 
	//print_ << "second byte in short [" << std::hex << _second_byte_short(x) << "]\n";

	print_ << "binary of i : "<< GREEN_FG << bit_i << RESETMODE << end_;
	newline_;
	print_ << "the function _Countl_zero_bsr      : " << std::_Countl_zero_bsr(i) << end_;
	print_ << "the function _Countl_zero_lzcnt    : " << std::_Countl_zero_lzcnt(i) << end_;
	print_ << "the function _Countl_zero_fallback : " << std::_Countl_zero_fallback(i) << end_;
	print_ << "the function countl_one            : " << std::countl_one((unsigned)i) << end_;
	print_ << "the function countl_zero           : " << std::countl_zero((unsigned)i) << end_;
	print_ << "the function countr_one            : " << std::countr_one((unsigned)i) << end_;
	print_ << "the function countr_zero           : " << std::countr_zero((unsigned)i) << end_;
	print_ << "the function " << std::

	wait_;
	return 0;
}







//int main()
//{
//	char c = 0xab;
//	uint64_t  int8byte = 0x0FAB'BCDB'BAAC'CDDA;
//
//	Print_(color::Lime, "integer 8 bytes ") << std::hex << int8byte << end_;
//
//
//
//	Print_(color::Red, "integer 8 bytes after swap ") << std::hex << i2 << end_;
//
//	cin.get();
//	return 0;
//}