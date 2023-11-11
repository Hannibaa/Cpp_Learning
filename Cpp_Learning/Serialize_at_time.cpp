#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <string>
#include <MyLib/stringfunctionhelper.h>
#include <MyLib/chrono/to_day.h>
#include <Mylib/vector_utility1.h>


using namespace std::literals;

std::vector<std::string> make_timename_filepaths(const std::string& _name, int _number) {

	auto current_path = fs::current_path();

	std::vector<std::string> vec_filenames{};

	for (int i = 0; i < _number; ++i) {
		vec_filenames.emplace_back(current_path.string() + "\\" + _name + "_" +
			                        Time::get_serial_at_time() + "_" + std::to_string(i));
	}

	return vec_filenames;
}


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
		file_serialized.insert(std::make_pair(Time::ToDay::String(),  current_path.string() + "\\_"s + Time::get_serial_at_time()));
		std::this_thread::sleep_for(1001ms); // we need some operation to be valid for map and multimap.
	}

	// if we want to serailize some files so :

	// print the resulte;
	print_ << "Print the value of multimap : " << end_;
	vu::print_map("this map for timing and serializing file : ", file_serialized);


	wait_;
	print_ << ERASESCREEN; 

	Print_(color::Green, "test a making vector") << end_;

	auto vec_files = make_timename_filepaths("hello", 6);

	for (auto& f : vec_files) print_ << f << end_;

	std::cin.get();
	return 0;
}