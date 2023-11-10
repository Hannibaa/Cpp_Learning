#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <string>
#include <MyLib/stringfunctionhelper.h>
#include <MyLib/chrono/to_day.h>
#include <Mylib/vector_utility1.h>


using namespace std::literals;


int main()
{
	auto time_serial = Time::get_serial_at_time();

	auto normal_time = Time::ToDay::String();

	Print_(color::Green, "first attempt: ") << end_;
	Print_(color::Red, time_serial) << end_;
	Print_(color::Red, normal_time) << end_;

	//std::map<std::string, std::string> file_serialized; // one for date and one for serialize file

	// if we changed to multimap ? 
	std::multimap<std::string, std::string> file_serialized;

	auto current_path = std::filesystem::current_path();

	Print_(color::Yellow, "current path : ") ;
	Print_(color::Red, current_path) << end_;

	for (int i = 0; i < 10; ++i) {
		std::this_thread::sleep_for(10ms); // we need some operation to be valid for map and multimap.
		file_serialized[Time::ToDay::String()] = current_path.string() + "_"s + Time::get_serial_at_time();
	}

	// if we want to serailize some files so :

	// print the resulte;

	vu::print_map("this map for timing and serializing file", file_serialized);


	std::cin.get();
	return 0;
}