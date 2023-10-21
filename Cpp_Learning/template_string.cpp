#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"

/*                TEST NTTP FOR STRING, DOUBLE , FLOAT , CLASSES ....                       
                  1. const char * 
				  2. fixed string template
				  3. double and float
*/


template<const char* str>
struct message {

	message() {
	            Print_(color::Green, str) << end_;
	}
};

// concepts for negative double : 
template<double D>
concept NegativeDouble = (D < 0.0);

// 1. double in template
template<double d>
requires NegativeDouble<d>   // for negative double 
void print_double() {
	std::cout << "this double is : " << d << end_;
}

template<double d>           // for positive double
void print_double() {
	std::cout << "this double is positive : " << d << end_;
}

//template<double d>
//	requires requires { d < 0.001 && d > - 0.001; }
//void print_double() {
//	std::cout << "this double is null.\n";
//}

// float 
template<float f>
void print_float() {
	std::cout << "float f : " << f << end_;
}

// using string and c string : 

// 1. make struct of fixed string const char[];
template<typename CharT,size_t N>
struct fixed_string {
	CharT data[N]{};
	constexpr fixed_string(const CharT(&str)[N]) {
		std::copy_n(str, N, data);
	}
};

// 2. make function use string 
template<fixed_string STR>
void print_fixed_string() {
	std::cout << "STRING : " << STR.data << end_;
}

int main()
{
//	message<"hello">(); // not allow.

	const char Msg[] = "Hello World";

	char Msg2[] = "This Array Type";

	//message<Msg> hi;
	//message<"this"> ho{};

	// use double in template
	print_double<3.5>();
	print_double<-4.55>();
	// +0.0 and - 0.0;
	print_double<0.0>();
	print_double<+0.0>();
	print_double<-0.0>();

	// use float in template 
	print_float<44.44f>();
	newline_;

	// using fixed string struct 
	fixed_string fs{ "hello world" };
	print_ << "fixed string : " << fs.data << end_;

	// tempate function of fixed string
	print_fixed_string<"this one">();
	//print_fixed_string<fs>();

	std::cin.get();
	return 0;
}