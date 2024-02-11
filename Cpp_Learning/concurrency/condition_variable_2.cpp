#include <iostream>
#include <conio.h>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "MyLib/Console_Library/escape_code.h"


std::mutex mut;
std::condition_variable cv;


const int g_minimum = 100;
int g_var{};

size_t szNum_threads = std::thread::hardware_concurrency();

bool g_stop = false;

void Working() {
	std::lock_guard<std::mutex> lock(mut);
	++g_var;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	printm_(2,3) << "value 1: " << g_var;
	cv.notify_one();
}

void Working2(int i) {
	std::unique_lock<std::mutex> ul(mut);
	cv.wait(ul, []()->bool {return g_var > -1; });
	--g_var;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	printm_(2, 5) << "value " << i << " : " << g_var;
}

int main() {

	std::vector<std::thread> vThreads(szNum_threads);
	std::thread thrStop([] {
		while (true) {
			if (_getch() == ESCAPE) {
				g_stop = true;
				break;
			}
		}
		});


	int th = 0;
	for (auto& thr : vThreads) {
		++th;
		thr = std::thread([&] {
			while (true) {
				Working(th);
				if (g_stop) break;
			}
			});
	}


	



	for (auto& thr : vThreads) thr.join();
	thrStop.join();

	return 0;
}