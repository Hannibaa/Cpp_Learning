#include <iostream>
#include <MyLib/Console_Library/escape_code.h>



int main() {

	auto a1 = ![] {};
	auto a2 = !![] {};
	auto a3 = -![] {};
	auto a4 = -~![] {};
	auto a5 = -~- ~![] {};
	auto a6 = -~- ~- ~![] {};
	auto a7 = -~![]{}<<-~-~-~![] {};



	print_ << "a1 = " << a1 << end_;
	print_ << "a2 = " << a2 << end_;
	print_ << "a3 = " << a3 << end_;
	print_ << "a4 = " << a4 << end_;
	print_ << "a5 = " << a5 << end_;
	print_ << "a6 = " << a6 << end_;
	print_ << "a8 = " << a7<< end_;

	return 0;
}