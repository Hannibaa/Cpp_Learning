#include <iostream>
#include <string>
#include <regex>

#include "MyLib/Console_Library/escape_code.h"

using namespace std::string_literals;


int main() {

		std::string text2 = R"(Determines if the regular expression e matches the entire 
target character sequence, which may be specified as std::string, a C-string, or an iterator pair.
1) Determines if there is a match between the regular expression e and the entire target
 character sequence [first,last), taking into account the effect of flags. When determining 
if there is a match, only potential matches that match the entire character sequence are considered.
 Match results are returned in m.
2) Behaves as (1) above, omitting the match results.
3) Returns std::regex match (str, str + std::char_traits<charT>::length(str), m, e, flags).
4) Returns std::regex match (s.begin(), s.end(), m, e, flags).
5) Returns std::regex match (str, str + std::char_traits<charT>::length(str), e, flags).
6) Returns std::regex match (s.begin(), s.end(), e, flags).
7) The overload 4 is prohibited from accepting temporary strings, otherwise this function populates 
match_results m with string iterators that become invalid immediately.)";


	std::regex re("[a-zA-Z]{5}");
	std::cmatch m;

	if (std::regex_search(text2.c_str(), m, re)) {  // returns true, and m[0] contains "Get"
		print_ << m.size() << end_;
		print_ << m[0] << end_;
	}
	
	print_ << text2.c_str() << end_;

	bool b_match = std::regex_match(text2.c_str(), m, re) ;

	if (b_match) {  // returns true, and m[0] contains "GetValue"
		print_ << "number of matches " << m.size() << end_;
		for (int p = 0; p < m.size(); ++p)
			print_ << "matches n " << p << " " << m[p] << end_;
	}

	wait_;
	return 0;
}



//int main() {
//	print_ << " Testing regex for first time \n";
//
//	std::string text("hello this my number 123.44443.66");
//	std::string text2 = R"(Determines if the regular expression e matches the entire 
//target character sequence, which may be specified as std::string, a C-string, or an iterator pair.
//1) Determines if there is a match between the regular expression e and the entire target
// character sequence [first,last), taking into account the effect of flags. When determining 
//if there is a match, only potential matches that match the entire character sequence are considered.
// Match results are returned in m.
//2) Behaves as (1) above, omitting the match results.
//3) Returns std::regex_match(str, str + std::char_traits<charT>::length(str), m, e, flags).
//4) Returns std::regex_match(s.begin(), s.end(), m, e, flags).
//5) Returns std::regex_match(str, str + std::char_traits<charT>::length(str), e, flags).
//6) Returns std::regex_match(s.begin(), s.end(), e, flags).
//7) The overload 4 is prohibited from accepting temporary strings, otherwise this function populates 
//match_results m with string iterators that become invalid immediately.)";
//
//
//
//	wait_;
//	return 0;
//}