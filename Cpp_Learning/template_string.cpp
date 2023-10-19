#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"


template<const char* str>
struct message {

	message() {
	            Print_(color::Green, str) << end_;
	}
};


int main()
{
//	message<"hello">(); // not allow.

	const char Msg[] = "Hello World";

	char Msg2[] = "This Array Type";

	//message<Msg> hi;
	//message<"this"> ho;

	std::cin.get();
	return 0;
}