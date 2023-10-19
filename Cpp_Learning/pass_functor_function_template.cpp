#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

template<typename T>
T func(T t) { return 3 * t; }


template<typename T>
struct Functor {
	static_assert(std::is_arithmetic_v<T>, "type should be arithmetic");
	T operator() (const T& t) { return t * t; }
};


template<typename T,typename Function = Functor<T>>
T Func(const T& t, Function F = Functor<T>()) {
	return F(t);
}

template<typename T, typename Function = decltype(func<T>) >
T Func2(const T& t, Function F = func<T>) {
	return F(t);
}



int main()
{
	Print_(color::Green, "Template Functor and Function") << end_;

	print_ << "1/) function pointer : " << Func(2.4f, func<float>) << end_;
	print_ << "2/) function lambda  : " << Func(35, [](int x)->int { return x % 7; }) << end_;
	print_ << "3/) functor          : " << Func(4.6, Functor<double>()) << end_;

	newline_;

	Print_(color::Green, "New we going testing argment default") << end_;

	print_ << "1.) function default argument : " << Func(55) << end_;
	print_ << "2.) this one fail : " << Func2(45) << end_;                // 

	std::cin.get();
	return 0;
}