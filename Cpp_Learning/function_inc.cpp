#include <iostream>
#include <string>
#include <concepts>
#include "MyLib/Console_Library/escape_code.h"

using namespace std::literals;

template<typename T>
concept has_plusplus = requires(T t) {  t++;  };

template<has_plusplus T, size_t N>
T inc_function() {
	static T i{};
	return i++;
}


int main()
{
	int k{};
	float f{};
	double d{};
	std::string str{};

	for (int i = 0; i < 10; ++i) {
		inc_function<int, 0>();
		inc_function<float, 0>();
		inc_function<double, 1>;
		inc_function<int, 1>();
	}

	Print_(color::Green, "print result : ") << inc_function<int, 0>() << end_;
	Print_(color::Green, "print result : ") << inc_function<float, 0>() << end_;
	Print_(color::Green, "print result : ") << inc_function<double, 1>() << end_;
	Print_(color::Green, "print result : ") << inc_function<int, 1>() << end_;
	Print_(color::Green, "print result : ") << inc_function<int, 2>() << end_;


	std::cin.get();
	return 0;
}