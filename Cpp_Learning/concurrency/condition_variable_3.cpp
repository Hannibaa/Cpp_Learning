#include "MyLib/Headers/concurrency_utility.hpp"

/*\
      We have of crech of programm that not like to terminated

*/


std::condition_variable  cv;
std::mutex               mutex;
bool                     stop{ false };

// product
std::string product{ "ab" };
size_t Size{ 100 };

// Producer subroutine
void add_char(char c) {
	std::lock_guard<std::mutex>  lg(mutex);
	product.push_back(c);
	cv.notify_one();
}

// Condition for consumation
bool Condition() {
	if (product.size() > Size) return true;
	return false;
}

// Consumer subroutine
void pop_char(size_t _Size = 100) {
	Size = _Size;
	std::unique_lock<std::mutex> ul(mutex);
	cv.wait(ul, Condition);
	product.pop_back();
}


int main() {

	std::thread thrProduction([] {
		while (true) {
			if (stop) break;
			Sleep(Milliseconds(400));
			add_char('K');
			printm_(2, 3) << "product : " << product;
		}
		});

	std::thread thrConsumer([] {
		while (true) {
			if (stop) {
				break;
			}
			Sleep(Seconds(1));
			pop_char(5);
			printm_(2, 5) << "Product : " << product;
		}
		});

	std::thread thrStop([] {
		while (true) {
			if (_getch() == 'q') {
				stop = true;
				break;
			}
		}
		});


	thrProduction.join();
	thrConsumer.join();
	thrStop.join();

	print_ << "end of program..." << end_;
	return 0;
}
