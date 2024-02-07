#include <iostream>
#include <syncstream>
#include <thread>

#include "MyLib/Console_Library/escape_code.h"

int count{};

int main() {

	if (count > 3) return -10;

	print_ << "count |" << count  << "| main thread Id : " << std::this_thread::get_id() << end_;

	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::thread thr(main);

	++count;

	//thr.detach();  // this here run only one thread and exit 
	thr.join();    // this here run count threads till reach condition and exit?????

	return 100;
}
