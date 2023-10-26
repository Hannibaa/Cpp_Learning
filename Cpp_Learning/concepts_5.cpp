#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <MyLib/Headers/my_concepts.h>

template<int K, typename T>
requires my_concept::Negative<int,K>
T process(T x) {
	if (K < 0) print_ << "negative number under -3 " << end_;
	if (K > 0) print_ << "positive number " << end_;

	return x;
}

template<typename T>
T x = static_cast<T>(2.4444545454545);

template<double D, typename T>
T y = std::bit_cast<T>(D);

template<size_t K, typename T>
T z = static_cast<T>(K);


int main()
{
	// process<4>(4.5);
	process<-36>(-44.01);

	print_ << process<-7>("hello");

	print_ << "number in float : " << x<float> << end_;
	print_ << "number in int   : " << x<int> << end_;
	print_ << "number in long long : " << x<size_t> << end_;

	newline_;
	
	print_ << "cast to int64  : " << y<3.5, int64_t> << end_;
	print_ << "cast to uint64 : " << y<5.66, size_t> << end_;
	print_ << "cast to double : " << y<56.7, double> << end_;


	wait_;
	return 0;
}