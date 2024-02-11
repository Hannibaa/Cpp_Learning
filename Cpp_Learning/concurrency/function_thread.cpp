#include <iostream>
#include <syncstream>
#include <thread>
#include "MyLib/containers.h"

void run_threads(int n) {
	std::vector<std::thread> vThreads;

	for (int k = 0; k != n; ++k)
		vThreads.push_back(std::thread{ [=] {
		std::osyncstream(std::cout) << k << " thread Id " << std::this_thread::get_id() << end_;
        } });

	std::this_thread::sleep_for(std::chrono::seconds(1));

	for (auto& thr : vThreads) thr.join();
}

std::thread::id  get_thread_id(std::thread& thread) {
	return thread.get_id();
}

int main() {
	run_threads(3);
	print_ << "main thread Id : " << std::this_thread::get_id() << end_;
	print_ << "waits little bit to run 5 threads " << end_;
	std::cin.get();

	run_threads(15);


	wait_;
	return 0;
}


