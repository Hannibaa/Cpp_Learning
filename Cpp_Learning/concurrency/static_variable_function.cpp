#include <iostream>
#include "MyLib/Console_Library/escape_code.h"




int& f() {
	static int k{};
	++k;

	return k;
}

int g() {
	static int d = f();

	++d;

	return d;
}

int main() {
	f() = 100;
	print_ << "first  call " << f() << end_;
	print_ << "second call " << f() << end_;
	print_ << "third  call " << f() << end_;

	f() = -1;
	print_ << "first call f after modification " << f() << end_;

	print_ << "first call g " << g() << end_;
	print_ << "second call g " << g() << end_;


	print_ << "end...\n";
	return 0;
}