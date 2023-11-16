#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include <MyLib/function_utility.h>
#include <MyLib/my_metaprog.h>


template<typename T>
void print_sizeof() {
	print_ << "size of " << typeid(T).name() << " is : " << Fn::max_v<T>() << end_;
}

int main()
{
	using T = int;
	print_sizeof<T>();
	print_sizeof<long long>();
	print_sizeof<size_t>();
	print_sizeof<std::string>();
	print_ << "max of int " << Fn::max_of<int> << end_;
	print_ << "max of char " << Fn::max_of<char> << end_;
	print_ << "max of size_t " << Fn::min_of<long> << end_;
	print_ << "max of string class " << Fn::max_of<std::string> << end_;

	wait_; cls();

	meta::first_arg_t<int, char, float> x{};
	meta::get_nth_type_t<2, int, char, float> y{};


	std::cin.get();
	return 0;
}