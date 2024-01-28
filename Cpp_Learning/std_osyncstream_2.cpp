#include <iostream>
#include <syncstream>
#include <thread>
#include <chrono>

#include "MyLib/Console_Library/escape_code.h"




int main()
{
	// safe output to the same stream (there it is std::cout)
	// without introducting data races.

	bool stop_ = false;

	auto j1 = std::jthread([]() {
		int count{ 20 };
		while(--count)
		{
			std::osyncstream(std::cout) << MOVETO(3,3) << count << "T";
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
		}

		});

	auto j2 = std::jthread([&]() {
		int count{ 20 };
		while (--count)
		{
			std::osyncstream(std::cout) << MOVETO(3,4) << count << "A";
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
		}

		stop_ = true;
		});


	// No interleaving, data are sent to std::cout
	// when osyncstream is destroyed.

	auto j3 = std::jthread([]() {
		{
			std::osyncstream out(std::cout);
			out << "This ";
			out << "will ";
			out << "not ";
			out << "be ";
			out << "interleaved.\n";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		{
			std::osyncstream(std::cout) << 
				"Maybe soneone said something before me.\n";
		}
		});

	auto j4 = std::jthread([&]() {
		while(true)
		{
			std::chrono::sys_seconds  sys_sec =
				std::chrono::floor<std::chrono::seconds>(std::chrono::system_clock::now());
			std::osyncstream(std::cout) << MOVETO(10,15) << sys_sec ;
			if (stop_) break;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			esc::clear_line(10, 15);
		}
		});

	/*
	Potential output :
	*/

	std::cin.get();
	return 0;
}