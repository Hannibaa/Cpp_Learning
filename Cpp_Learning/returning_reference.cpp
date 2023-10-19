#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <array>
#include <string>
#include <string_view>
#include <span>

using namespace std;

int& fun_ref() {

	int i{ 100 };

	return i;
}

int fun_value() {
	
	int i{ 200 };

	return i;
}


auto lambda() {

	int i{ 400 };

	return [=] {return i + 2; };
}

auto lambda_ref() {
	
	int i{ 500 };

	return [&] {return i + 10; };
}


int main()
{
	print_ << "fun() = " << fun_ref() << end_;

	fun_ref() = 200;

	print_ << "fun() = " << fun_ref() << end_;

	int& k = fun_ref();    // here why should not return a reference

	print_ << "k = " << k << end_;   //  k = -23424324342; ???

	//second return by value

	print_ << "fun() = " << fun_value() << end_;

	int kk = fun_value();    // int& kk = fun_value() ; // not working

	print_ << "kk = " << kk << end_;

	// fun_value() = 300;  // this code is not working

	auto j = lambda();

	print_ << "lambda " << j() << end_;                     // return 402

	print_ << "lambda ref = " << lambda_ref()() << end_;    // should return 510 but return 37654 any number every
	                                                        // every time because reference.



	cin.get();
	return 0;
}