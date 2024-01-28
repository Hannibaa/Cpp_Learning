#include <iostream>
#include <syncstream>
#include <thread>
#include <chrono>

#include "MyLib/Console_Library/escape_code.h"




int main()
{
	// safe output to the same stream (there it is std::cout)
	// without introducting data races.
	auto j1 = std::jthread([]() {
		std::osyncstream(std::cout) <<
			"THREAD 1 : We can safely write to the same stream. \n";
		});

	auto j2 = std::jthread([]() {
		std::osyncstream(std::cout) <<
			"THREAD 2 : We can safely write t the same stream. \n";
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

	auto j4 = std::jthread([]() {
		std::osyncstream(std::cout) << "Hey!\n";
		});

	/*
	Potential output :
	*/
	
	std::cin.get();
	return 0;
}