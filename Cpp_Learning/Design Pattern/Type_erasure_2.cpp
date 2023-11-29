/*
		  These exemples taken from CppCon of Mr. Klaus.I. Type Erasure
		  Author : KADDA Aoues
*/

#include <iostream>
#include <functional>
#include "Type_erasure_2.h"


template<typename R, typename...Ts>
constexpr R _func(std::function<R(Ts...)> _f, Ts...ts) {
	return _f(ts...);
}


void f1(int x) {
	Print_(color::Aqua, "print x ") << x << end_;
}



void func(std::function<void(int)> command, int i) { // this good solution
	command(i); 
}


template<typename F>
void func1(F f, int i) {  // This not good solution 
	f(i);
}

int main()
{

	PrintCommand pc{};
	_func<void,int>(pc, 9);

	SearchCommand sc{};
	func(sc, 100000000);

	ExecuteCommand ec{};
	func(ec, 100);

	_func<void, int>(f1,233);

	_func<void,int>([](int x)->void { print_ << "x[" << x << "]\n"; }, 5000000);

	std::cin.get();
	return 0;
}