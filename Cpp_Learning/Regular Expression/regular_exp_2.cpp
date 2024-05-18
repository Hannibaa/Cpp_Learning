/* 
        Looking to understand the basic of regular expression
*/

#include <iostream>
#include <regex>
#include <random>

#define end_ '\n'

int main() {

    std::string str = "25543434499343594548766499939";

    std::random_device rd{};
    std::mt19937 eng(rd());

    std::uniform_int_distribution<int>  Char{ 0,9 };


	std::cout << "Old String : " << str << end_;

    for (int i = 0; i < 10; ++i) {
        auto pstr = std::to_string(Char(eng));
        pstr = pstr + "|" + std::to_string(Char(eng));
        std::regex pattern(pstr);
        std::cout << "New String : " << std::regex_replace(str, pattern, "*") << end_;
    }

    return 0;
}
