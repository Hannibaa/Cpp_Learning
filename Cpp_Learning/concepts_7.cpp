#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

/* 
        From CppCon 'Handrik Niemeyer'
		C++20 concept and template feature
*/

// 1. make overloading resolution

struct No_Stringable {

};

template<typename T>
concept A = std::floating_point<T>;

// todo negation of concept
// todo make concepts for no stringable object.
template<typename T>
concept S = requires(T t) {
	std::cout << t;
};

// todo make concept for any function
template<typename _F>
concept anyFunction = requires(_F f) {
	f(...);
};

template<typename _F, typename _R, typename _Arg>
concept Functions = std::regular_invocable<_F,_Arg> && 
                   std::same_as<std::invoke_result_t<_F,_Arg>, _R>;

template<typename T>
void Print(T x) {
	Print_(color::Green, "Without Concepts Print") << end_;
}

template<typename T> requires A<T>
void Print(T x) {
	Print_(color::Red, "With Concept A and S") << end_;
}


template<typename T> requires S<T> && A<T>
void Print(T x) {
	Print_(color::Red, "With Concept S") << end_;
}


template<typename T, typename ...Args > 
	requires std::is_invocable<T, Args...>::value
void Print(T x) {
	Print_(color::Fuchsia, "Is function : ") << typeid(T).name() << end_;
}

template<typename F>
requires Functions<F,float,float>
void Print(F f) {
	Print_(color::Yellow, "is function ; ") << typeid(F).name() << end_;
}

int g(...) {
	print_ << COLOR(color::Red, "function take any thing") << end_;

	return 0;
}

int main()
{
	Print(23);
	Print(3.f);
	Print('A');
	Print(No_Stringable{});

	Print(std::sinf);

	std::cin.get();
	return 0;
}