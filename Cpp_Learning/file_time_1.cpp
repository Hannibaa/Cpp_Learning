#include <iostream>
#include <chrono>
#include <sstream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/CFile.h"

// todo Issue to convert nano to time_point.
int main()
{
	fs::path file = R"(C:\Users\Acer\source\Course C++\Cpp_Learning\Cpp_Learning\time_1.cpp)";

	fs::file_time_type ftime = fs::last_write_time(file);

	auto rep = ftime.time_since_epoch().count();

	// fs::file_time_type ftime2 = fs::file_time_type{ nanoseconds{rep} }; // not acceptable
	                                                                        // not accurate

	microseconds micro = std::chrono::duration_cast<microseconds>(nanoseconds(rep));
	milliseconds mil = std::chrono::duration_cast<milliseconds>(nanoseconds(rep));
	fs::file_time_type ftime3 = fs::file_time_type{ mil };    // this acceptable but 

	fs::file_time_type ftime2 = fs::file_time_type{ micro };
	 
	print_ << "time is " << ftime << end_;
	print_ << "time is " << micro.count() << "|" << ftime2 << end_;
	print_ << "time is " << ftime3.time_since_epoch().count() << "|" << ftime3 << end_;
	print_ << "time is " << ftime.time_since_epoch() << end_;
	print_ << "time is " << ftime.time_since_epoch().count() << end_;
	

	std::cin.get();
	return 0;
}