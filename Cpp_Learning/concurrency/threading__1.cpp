#include <iostream>
#include <thread>
#include <functional>
#include <conio.h>
#include "MyLib/Console_Library/escape_code.h"



#define Exemple_3

#ifdef Exemple_3

std::string  buffer{};

bool runing = true;

void pop() {
	if (!buffer.empty())
		buffer.pop_back();
}

void push_back(char c) {
	buffer.push_back(c);
}



int main() {
	Print_(color::Green, "Threading with mutex") << end_;

	std::thread thrStoper([] {
		while (runing) {
			if (_getch() == ESCAPE) {
				runing = false;
				break;
			}
		}
		});

	std::thread thr1([] {
		while (runing) {
			push_back('A');
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		});

	std::thread thr11([] {
		while (runing) {
			push_back('B');
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		});

	std::thread thr2([] {
		while (runing) {
			pop();
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		});

	std::thread thrPrint([] {
		while (runing) {
			esc::clear_line(1, 4);
			printm_(1, 4) << buffer << end_;
			std::this_thread::sleep_for(std::chrono::milliseconds(550));
		}
		});






	thrPrint.detach();
	thrStoper.detach();
	thr2.join();
	thr1.join();
	thr11.join();
	wait_;
	return 0;
}



#endif // Exemple_3







#ifdef Exemple_2

// empty thread cause error abort even by std::function

int main() {
	Print_(color::Green, "thread id : ") << std::this_thread::get_id() << end_;

	std::thread  thr([] {print_ << "thread id : " << std::this_thread::get_id() << end_; });


	thr.join();
	print_ << "End program...\n";
	return 0;
}



#endif  // Exemple 2





#ifdef  Exemple_1


void write_string(std::string& str, char c, int times) {
	Print_(color::Red, "thread id : ") << std::this_thread::get_id() << end_;

	for (int i = 0; i < times; ++i) str.push_back(c);
}

void write_out(char c, int times) {
	Print_(color::Red, "thread id : ") << std::this_thread::get_id() << end_;
	for (int i = 0; i < times; ++i) print_ << c;
	print_ << end_;
}



// threading transfer owner shipe
int main() {
	Print_(color::Green, "thread id main") << std::this_thread::get_id() << end_;
	std::string buffer;

	std::thread  thr(write_string, std::ref(buffer), 'Q', 100);
	std::thread  thr2(write_out, 'K', 50);
	std::thread  thr3 = std::move(thr2);


	//thr2.join();
	thr.join();
	thr3.join();
	print_ << "result : " << buffer.size() << " | " << buffer << end_;
	print_ << "End ...\n";
	return 0;
}

#endif  // Exemple_1