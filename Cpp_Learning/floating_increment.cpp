#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include "c:\Users\Acer\source\MyLib\math_functions.h"


using namespace std;



int main()
{
	print_ << GREEN_FG << " Floating Increment Test Functions " << RESETMODE << end_;

	double f = 2.5000313;

	print_ << "integer conversion bit to bit : " << std::bit_cast<int64_t>(f) << end_;
	print_ << "double f         : " << f << end_;
	print_ << "increment by 1   : " << Math::float_inc(f) << end_;
	print_ << "increment by 100 : " << Math::float_inc(f,100) << end_;
	print_ << "float of int (1)   " << std::bit_cast<float>(1) << end_;
	print_ << "float of int (100) " << std::bit_cast<float>(100) << end_;
	wait_;
	for (int i = 0; i < 10000; ++i) {
		print_ << "increment by 1 : " << Math::float_inc(f,10000000) << end_;
	}

	cin.get();
	return 0;
}