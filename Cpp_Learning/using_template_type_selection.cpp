#include <iostream>
#include <vector>
#include "MyLib/Console_Library/escape_code.h"
#include "meta_programming.h"


int main()
{
	Vec<char> vec_char;
	Vec<float> vec_float;

	Int_t<3> i;
	Int_t<8> c;

	Int_t<_2n<11>> g;

	i = 0b11100;


	for (int k = 0; k < 30; ++k) {
		i = k;
	     print_ << "int i is " << i << end_;
		 wait_;
	}

	static_assert(_2N<35>() == 64);
	static_assert(_2n<17> == 32);
	static_assert(_2n<64> == 64);

	print_ << "test _2N " << _2N<34>()() << end_;
	print_ << "test 2 _2N : " << _2N<11>() << end_;
	print_ << "test 3 _2n : " << _2n<13> << end_;
	//print_ << "test 4    : " << _2n<'a'> << end_; // 'a' = 97.
	


	std::cin.get();
	return 0;
}