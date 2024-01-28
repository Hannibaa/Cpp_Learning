#include <iostream>
#include <array>
#include <string>
#include <string_view>
#include <MyLib/Console_Library/escape_code.h>

/*
    checking the two new member functions of std::string checking suffix and prefix : 
	  1. ends_with();
	  2. starts_with();
*/

int main() {

	Print_(color::Green, "Presentation of new feature of string lib c++20") << end_ ;

	std::array<std::string, 3> str;
	 
	str[0]  = R"(hello world; we are here.)";
	str[1]  = R"(hella world; we are here!)";
	str[2]  = R"(hello world; we are here;)";

	print_ << "size of string : " << str.size() << end_;
	int i{};
	for (const auto& s : str) {
		print_ << "string n : " << ++i << end_;
		if (s.ends_with('.')) print_ << "this string end with ." << end_;
		if (s.starts_with("hello")) print_ << "this string start with hello " << end_;
		print_ << "--------------------------------------------------------\n";
	}


	Print_(color::Green, "---------------------------- end -------------------------") << end_;
	wait_;
	return 0;
}