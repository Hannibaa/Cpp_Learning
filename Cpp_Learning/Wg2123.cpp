#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

constexpr int x = 10;

auto foo() {
	constexpr static const int* p = &x;

	struct A {
		const int* const& getPtr() {
			return p;
		}
	} a;

	return a;
}

int xcpy = * decltype(foo()){}.getPtr();

int main()
{

	print_ << "this:" << xcpy << end_;

	std::cin.get();
	return 0;
}