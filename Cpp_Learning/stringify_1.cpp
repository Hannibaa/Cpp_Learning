#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

#define INT_TYPE(Size)     int##Size##_t
#define INT_(Size)         int##Size##_t
#define MAKE_VAR(V1,V2)    V1##_##V2
#define VAL(K)             K

int main()
{
	int k{};

	int m = sizeof(int);

	int  INT_(hello);

	INT_TYPE(32)   a {};
	INT_TYPE(64)   b {};
	INT_TYPE(16)   c {};
	INT_TYPE(8)    d {};

	int MAKE_VAR(a, b) {};


	print_ << "size of a " << sizeof(a) << end_;
	print_ << "size of b " << sizeof(b) << end_;
	print_ << "size of c " << sizeof(c) << end_;
	print_ << "size of d " << sizeof(d) << end_;
	print_ << "variable a_b " << a_b << end_;



	std::cin.get();
	return 0;
}