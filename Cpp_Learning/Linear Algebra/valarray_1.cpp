#include <iostream>
#include <valarray>
#include <array>
#include "MyLib/Console_Library/escape_code.h"


std::string operator-(const std::string& s1, const std::string& s2) {
	return s1 + s2;
}


int main() {

	std::valarray<std::string>  vstr{ "hello", "world", "?" };
	std::valarray<std::string>  vstr2{ "hello", "world", "?" };

	print_ << "size of vstr " << vstr.size() << end_;

	auto v = vstr + vstr2;
	auto vv = vstr - vstr2;

	print_ << "string added : " << end_;
	for (auto& str : vv) print_ << str << end_;
	


	wait_;
	return 0;
}