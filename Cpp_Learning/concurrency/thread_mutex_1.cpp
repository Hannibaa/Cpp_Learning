#include <iostream>
#include <syncstream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <conio.h>

#include <MyLib/Console_Library/escape_code.h>

#define time_now            std::chrono::steady_time::now()
#define Seconds(n)          std::chrono::seconds(n)
#define Milliseconds(n)     std::chrono::milliseconds(n)
#define Sleep(n)            std::this_thread::sleep_for(n)




/*
     we don't implement any mutex for these concurenct data :
	 for 1st exemple : int& 
	 for 2nd exemple : string&
*/


// second exemple with string class that is more complex than integer:

std::mutex mutex;
bool stop = false;
std::string data_("Hello!--------------------------------------------------------");

void add_char(char c) {
	//std::lock_guard lg(mutex);
	data_.push_back(c);
}

void pop_char() {
	//std::lock_guard lg(mutex);
	data_.pop_back();
}

void print_string(int x,int y) {
	std::osyncstream(print_) << MOVETO(x,y) << "thrId " << std::this_thread::get_id()
		<< " : [" << data_ << "]";
}

void clear_line(int x, int y) {
	std::osyncstream( print_)<< MOVETO(x,y) << ERASELINE;
}


int main() {

	std::thread thr1([] {
		while (true) {
			if (stop) break;
			add_char('A');
			print_string(2,3);
			clear_line(2,3);
		}
		});

	std::thread thr2([] {
		while (true) {
			if (stop) break;
			add_char('B');
			print_string(2,5);
			clear_line(2, 5);
		}
		});

	std::thread thrSizeCondition([] {
		while (true) {
			if (stop) break;
			if (data_.size() > 100) {
				std::osyncstream(print_)<< MOVETO(2,9) << "maximum size of string ...";
				stop = true;
				break;
			}
		}
		});

	std::thread thrPop([] {
		while (true) {
			if (stop) break;
			if (data_.size() > 10) { 
				data_.pop_back(); 
				//print_string(2,7);
			}
		}
		});

	// thread for stoping all loops
	std::thread thrStop([] {
		while (true) {
			if (_getch() == 'q') {
				stop = true;
				break;
			}
		}
		});


	thrStop.join();
	thrPop.join();
	thr1.join();
	thr2.join();
	thrSizeCondition.join();

	return 0;
}

/*     // first exemple 1

int count{1000};
bool stop = false;

void add_count() {
	++count;
}

void take_count() {
	--count;
}

void print_count(std::string_view of_thread_id = "") {
	print_ << of_thread_id << "count : " << count << end_;
}


int main() {
	std::thread thr1([] {
		while (true) {
			if (stop) break;
			Sleep(Seconds(1));
			add_count();
			print_count("thread 1");
		}
		});

	std::thread thr2([] {
		while (true) {
			if (stop) break;
			Sleep(Milliseconds(1000));
			take_count();
			print_count("thread 2");
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


	//while (!stop) {
	//	Sleep(Milliseconds(400));
	//	print_count();
	//}

	thrStop.join();
	thr2.join();
	thr1.join();

	print_ << "end of program...\n";
	return 0;
}

*/