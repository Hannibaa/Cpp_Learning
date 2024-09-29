#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <future>
#include <ctime>
#define end_                   '\n'

std::string make_daytime_string() {
	time_t now = time(nullptr);
	return ctime(&now);
}

std::string make_daytime_string2() {
	time_t now = time(nullptr);
	char buf[256];
	ctime_s(buf, 256, &now);
	return buf;
}

void compl_handler(std::error_code ec, size_t size, void f()) {
	if (!ec) {
		std::cout << "size is " << size << end_;
	}
	else {
		std::cout << "error is " << ec.message() << end_;
	}

	f();
}

void initiator_function() {
	std::error_code ec;
	size_t size;
	std::cout << make_daytime_string2() << "thread Id : " << std::this_thread::get_id() << end_;
	std::async(std::launch::async, compl_handler, ec, size, initiator_function);
	std::async(std::launch::async, [] {
		std::cout << "second async : thread id : " << std::this_thread::get_id() << end_;
		initiator_function();
		});
}


int main() {

	std::cout << "start of program" << end_;

	initiator_function();


	std::cout << "end of program" << end_;
	std::cin.get();
	return 0;
}



