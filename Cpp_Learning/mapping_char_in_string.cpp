#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include <map>
#include <vector>
#include <string>
#include <string_view>
#include <sstream>
#include <algorithm>
#include <MyLib/vector_utility1.h>
#include <MyLib/stringfunctionhelper.h>


// is one of the characters



// FUNCTION testing function is_one_of()

int main() {

	std::string text = "2342 is one Of ONE and one or?";

	std::string test_string = "abcAO";

	for( char c = 'a' ; c != 'z' + 1 ;++c )
	print_ << "is there this cahr " << c << " in text : " << Str::is_one_of(c, text) << end_;


	wait_;
	return 0;
}


////   FUNCTION  get_mapping_word_in_text()
//
//int main()
//{
//	auto map = Str::get_mapping_word_in_text("hello how are you? it's okey");
//
//	vu::print_map("mapping of char in text : ", map);
//
//	std::string text{};
//	print_ << "enter any text : " << end_;
//	std::getline(std::cin, text);
//
//	map = Str::get_mapping_word_in_text(text);
//
//	vu::print_map("text get from cin ", map);
//
//	print_ << "end......" << end_;
//
//	wait_;
//	return 0;
//}






////      FUNCTION  get_words()
//
//int main() {
//
//	std::string text = "hello, how are you? is there any one here!.";
//	std::string text2 = "this??";
//	std::string text3 = "this??yes!";
//	std::string text4 = "this??yes! hi";
//
//	auto vec_str = Str::get_alpha_words(text4);
//
//	print_ << "vector size is " << vec_str.size() << end_;
//
//	Vector_Utility::print_container(vec_str);
//
//	wait_;
//	return 0;
//}




//          FUNCTION get_mapping_character_in_text()
// 
// int main()
//{
//	auto map = get_mapping_character_in_text("hello how are you? it's okey");
//
//	print_map("mapping of char in text : ", map);
//
//	std::string text{};
//	print_ << "enter any text : " << end_;
//	std::getline(std::cin, text);
//
//	map = get_mapping_character_in_text(text);
//
//	print_map("text get from cin ", map);
//
//	print_ << "end......" << end_;
//
//	wait_;
//	return 0;
//}