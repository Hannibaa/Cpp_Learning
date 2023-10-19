#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <variant>
#include "MyLib/Console_Library/escape_code.h"
#include <MyLib/stringfunctionhelper.h>


using namespace std;

union Integer {
	char    Char;
	short   Short;
	int     Int;
	int64_t Int64;
};

using IntVariant = std::variant<char, short, int, int64_t>;

IntVariant str_to_integer(std::string_view word_8_chars) {
	int l = word_8_chars.length();
	if ( l > 8) {
		print_ << RED_BG << "Enter 8 character word please " << RESETMODE << end_;
		return {};
	}

	char c[8]{};
	for (int i = 0; i < l; ++i) c[i] = word_8_chars[i];

	uint64_t i64 = std::bit_cast<uint64_t>(c);

	IntVariant Integer;

	if (l == 1) return  static_cast<char>(i64);
	else
		if (l == 2) return static_cast<short>(i64);
		else
			if (l == 4) return static_cast<int>(i64);
			else
				return static_cast<int64_t>(i64);
}

template<typename T>
std::string integer_to_str(const T& value) {
	static_assert(std::is_integral_v<T>, "T should be integer type");

	char* c = (char*)&value;

	return std::string(c,c+sizeof(T));
}

//reverse string
std::string str_reverse(std::string str) {
	
	std::reverse(str.begin(), str.end());

	return str;
}

//int main() {
//	auto i = str_to_integer("Aoues");
//	print_ << " i = " << i << end_;
//	auto str = integer_to_str(i);
//
//	print_ << "string is " << str << end_;
//	print_ << "revers it " << str_reverse(str) << "  " << str <<  end_;
//
//	wait_;
//	return 0;
//}





int main()
{
	auto i = str_to_integer("Aoueswer");
	auto k = str_to_integer("Kadda");
	std::string str{};
	print_ << "Enter string to integralized : \n";
	std::cin >> str;

	auto j = str_to_integer(str);
	print_ << RED_FG << str << RESETMODE << end_;

	print_ << "i " << std::get<int64_t>(i) << end_;
	if (std::holds_alternative<char>(j)) print_ << "j(char) " << std::get<char>(j) << end_;
	if (std::holds_alternative<short>(j)) print_ << "j(short) " << std::get<short>(j) << end_;
	if (std::holds_alternative<int>(j)) print_ << "j(int) " << std::get<int>(j) << end_;
	if (std::holds_alternative<int64_t>(j)) print_ << "j(int64) " << std::get<int64_t>(j) << end_;

	cin.get();
	return 0;
}