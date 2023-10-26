#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

/*   
     BIT FIELD  C++     
	 AUTHOR : KADDA AOUES
	 DATE   : 25 OCTOBER 2023 
*/


struct bit_field {
	unsigned char c1 : 1;
	unsigned char c2 : 1;
	unsigned char c3 : 1;
	unsigned char c4 : 1;
	unsigned char c5 : 4;
};




union oct2 {
		char C;
		struct {
			unsigned char o1 : 4;
			unsigned char o2 : 4;
		};
};


struct Float32 {
	union {
		float fValue;
		struct {
			unsigned int mantissa : 23;
			unsigned int exponent : 8;
			unsigned int sign : 1;
		};
	};

	Float32(float f) :fValue(f) {}
};



int main()
{
	print_ << "size of bit field " << sizeof(bit_field) << end_;

	bit_field bit{};
	oct2 _oct{};


	bit.c1 = 2;
	bit.c5 = 0xfe;
	_oct.C = 0xba;

	print_ << "bit is c1 [" << (int)bit.c1 << "] type is : " << typeid(bit.c1).name() << end_;
	print_ << "bit is c5 [" << (int)bit.c5 << "] type is : " << typeid(bit.c5).name() << end_;
	print_ << "oct field [" << (int)_oct.C << "] type is :" << typeid(oct2).name() << end_;
	print_ << "oct 1 " << (int)_oct.o1 << end_;
	print_ << "oct 2 " << (int)_oct.o2 << end_;

	std::cin.get();
	return 0;
}