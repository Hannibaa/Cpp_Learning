#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "getsubtype.h"

/* 
           reinterpret_cast<T*>(ptr) , always here ptr is pointer 
		   and some of other
		   
		   */

using namespace std;



int main()
{
	uint64_t i64 = 0xff00'deaa'ccee'ddbb;

	Print_(color::Green, std::hex << "i64 = " << i64) << end_;

	char*  array_char{};
	short* array_short{};
	int*   array_int{};

	char a[8]{};
	// if we like to put i64 in char[8]
    

	Print_(color::Lime, "casting by using reinterpret_cast") << end_;
	array_char = reinterpret_cast<char*>(&i64);

	for (int i = 0; i < 8; ++i)
		print_ << hex << (short)array_char[i] << " ";
	newline_;

	Print_(color::Green, "casting by using memcpy") << end_;
	std::memcpy(a, (char*)&i64 + 4, 1);
	for (int i = 0; i < 8; ++i)
		print_ << hex << (short)a[i] << " ";

	Print_(color::Green, "using function template") << end_;
	print_ << "get 6th char in i64 : " << (int)get_char(i64, 5) << end_;

	Print_(color::Red, "using function template getSubType") << end_;
	print_ << "get 2 short : " << getSubType<short>(i64, 1) << end_;

	Print_(color::Green, "using function template getSubType") << end_;
	print_ << "get low and hi int in i64 " << getSubType<int>(i64,0) << " " << 
		                                      getSubType<int>(i64,1) << end_;


	cin.get();
	return 0;
}