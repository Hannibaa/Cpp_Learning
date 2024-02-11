#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <conio.h>
#include <condition_variable>

#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/container_utility.h"


int g_x = 0;
std::string g_str;

bool g_stop = false;



int main() {

	std::thread thrAdd([] {
		while (true) {
			if (g_stop) break;
			char c = _getch();

			g_str.push_back(c);
		}
		});

	std::thread thrPop([] {
		while (true) {
			if (g_stop) break;
			if (!g_str.empty() ) g_str.pop_back();

			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		});

	std::thread thrStop([] {
		while (true) {
			if (_getch() == ESCAPE) {
				g_stop = true;
				break;
			}
		}
		});

	while (true) {
		printm_(2, 5) << "string : " << g_str;

		if (g_stop) break;

		esc::clear_line(2, 5);
	}

	thrAdd.join();
	thrPop.join();
	thrStop.join();

	return 0;
}








//void Get_Char(char& c) {
//	
//	while (true) {
//		c = _getch();
//		g_stop = true;
//		if (c == ESCAPE ) break;
//	}
//}
//
//
//int main() {
//	char k{};
//	char q{};
//	std::thread thr1(Get_Char, std::ref(k));
//	std::thread thr2(Get_Char, std::ref(q));
//
//	//std::thread thrPrint([=] {
//	//	while (true)
//	//	{
//	//		if (g_stop) {
//	//			print_ << "print k " << k << end_;
//	//			print_ << "print q " << q << end_;
//	//		    g_stop = false;
//	//		}
//	//		
//	//		if (k == ESCAPE) break;
//	//	}
//	//	});
//
//	while (true)
//	{
//		if (g_stop) {
//			print_ << "print k " << k << end_;
//			print_ << "print q " << q << end_;
//			g_stop = false;
//		}
//
//		if (k == ESCAPE) break;
//	}
//
//	thr1.join();
//	thr2.join();
//	//thrPrint.detach();
//
//	return 0;
//}
//



//int main() {
//
//	std::thread thr1([] {
//		while(true)
//		{
//			g_str += "abcdefghijk"[rand() % 11];
//			std::this_thread::sleep_for(std::chrono::seconds(1));
//		}
//		});
//
//	std::thread thr2([] {
//		while(true)
//		{
//			g_str += "ABCDEFGHIJK"[rand() % 11];
//			std::this_thread::sleep_for(std::chrono::seconds(1));
//		}
//		});
//
//	std::thread thr3([] {
//		while(true)
//		if (g_str.size() > 20) g_str = g_str.substr(3);
//		});
//
//	std::thread thrStoper([] {
//		while (true) {
//			if (_getch() == 'q') g_stop = true;
//		}
//		});
//
//	while (true) {
//
//		print_ << "string is : " << g_str << end_;
//
//		if (g_stop) break;
//
//		esc::cls();
//	}
//
//
//	thr1.detach();
//	thr2.detach();
//	thr3.detach();
//	thrStoper.detach();
//
//
//	print_ << "End Program..." << end_;
//	return 0;
//}


//int main() {
//	int m_x = 0;
//	// Make two loop thread that try every time to change global variable g_x and g_string
//	std::thread thr1([] {while (true) g_x = 100; });
//	std::thread thr2([] {while (true) g_x = 999; });
//
//	// this additional thread to stop the program from running
//	std::thread thr3([] { while (true) {
//		if (_getch() == 'q') g_stop = true;
//	}});
//
//	while (true) {
//		if (g_x == 100)
//			Printm_(1,3,color::Green, "Thread 1 ") << g_x << end_;
//		else
//			if (g_x == 999)
//				Printm_(1,5,color::Red, "Thread 2 ") << g_x << end_;
//
//		 if (g_stop) break;
//
//		 std::this_thread::sleep_for(std::chrono::milliseconds(500));
//		 esc::cls();
//	}
//
//	//thr1.join();  // this keep programming waiting for thread to terminate but has inifinit loop
//	//thr2.join();
//
//	thr1.detach();  // this better, terminate thread will exit loop 
//	thr2.detach();
//	thr3.detach();
//
//	return 0;
//}