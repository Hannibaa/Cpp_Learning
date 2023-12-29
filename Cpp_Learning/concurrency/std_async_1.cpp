#include <iostream>
#include <thread>
#include <future>

#include "MyLib/Console_Library/escape_code.h"

// todo async and future and mutex.

int main()
{
	Print_(color::Green, "ASYNCR") << end_;

	print_ << "main thread id[" << std::this_thread::get_id() << end_;

	std::future<void> f_void = std::async(std::launch::async, []
		{print_ << "id[" << std::this_thread::get_id() << end_;
	     std::this_thread::sleep_for(std::chrono::seconds(6));
	     print_ << "hello async\n";
	 });

	print_ << "waiting ..." << end_;

	f_void.wait_for(std::chrono::seconds(4));

	print_ << "end..." << end_;

	std::cin.get();
	return 0;
}