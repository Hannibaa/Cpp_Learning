#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include <MyLib/function_utility.h>


template<typename T>
void print_sizeof() {
	print_ << "size of " << typeid(T).name() << " is : " << Fn::max_value<T>() << end_;
}

int main()
{
	using T = int;
	print_sizeof<T>();
	print_sizeof<long long>();
	print_sizeof<size_t>();

	print_ << "max of int " << Fn::max_of<int> << end_;
	print_ << "max of char " << Fn::max_of<char> << end_;

	print_ << "max of size_t " << Fn::max_of<size_t> << end_;

	std::cin.get();
	return 0;
}