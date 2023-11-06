#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <string>
#include <MyLib/stringfunctionhelper.h>
#include <MyLib/chrono/to_day.h>


using namespace std::literals;


int main()
{
	std::map<std::chrono::sys_days, std::string> local;

	auto firstdays = 2021y / 1 / std::chrono::last;

	auto lastdays = 12 / 31d / 2021;

	for (auto d = firstdays; d <= lastdays; d += std::chrono::months(1)) {
		local.emplace(d, Str::getRandomString2(12));
		std::cout << "day :[" << d << "] " << '\n';
	}

	for (auto& l : local) {
		std::cout << " day ; [" << l.first << "]   ";
		std::cout << " string " << l.second << '\n';
	}


	std::cin.get();
	return 0;
}