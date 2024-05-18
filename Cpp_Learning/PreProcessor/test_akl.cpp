#include <iostream>
#include <MyLib/Console_Library/escape_code.h>

#include "general_macro.h"

void f(int a) {
	std::cout << "print a : " << a << end_;
}

int main() {

	int b{};

	int a = 3;

	f(AKL_ARG_1(a, b));

}