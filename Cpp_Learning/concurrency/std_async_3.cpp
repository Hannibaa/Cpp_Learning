#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include "MyLib/Console_Library/escape_code.h"

// trying two different mutex
// one mutex
// without mutex,
// join() and detach() function
// ... todo


static std::mutex muStdout;
static std::mutex muStdout2;
namespace tm_ = std::chrono;

void print_time(int x) {
	while (--x > 0) {
		{
			std::lock_guard<std::mutex> lock(muStdout);
			printm_(50, 1) << "time[" <<
				tm_::time_point_cast<tm_::seconds>(std::chrono::system_clock::now()) << end_;
		}
		std::this_thread::sleep_for(tm_::seconds(1));
		esc::clear_line(1, 1);
	}
}

void decrement(int& x) {
	while (--x > 0) {
		{
			std::scoped_lock<std::mutex> lock(muStdout);
			printm_(50, 2) << "decremental[" << --x << "]" << end_;
		}
		std::this_thread::sleep_for(tm_::seconds(1));
		esc::clear_line(1, 2);
	}
}


int main() {

	int x = 10;
	int y = 15;

	std::thread t1(print_time, std::ref(x));
	decrement(y);


	t1.join();

	wait_;
	return 0;
}






//int main()
//{
//
//
//	int x = 20;
//
//	while (--x) {
//		tm_::sys_seconds tp = tm_::time_point_cast<tm_::seconds>( tm_::system_clock::now());
//		printm_(20, 1) << "time : " << tp << end_;
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//		esc::clear_line(1, 1);
//	}
//
//	x = 20;
//	while (--x) {
//		printm_(23, 2) << "Decrement : " << x << end_;
//		std::this_thread::sleep_for(tm_::seconds(1));
//		esc::clear_line(1, 2);
//	}
//
//
//	printm_(1, 10) << "End...\n";
//
//	//t1.join();
//	//t2.detach();
//
//	std::cin.get();
//	return 0;
//}