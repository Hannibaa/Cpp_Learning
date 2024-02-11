#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/container_utility.h"

using vecThread = std::vector<std::thread > ;
const int NUM_THR = 10;

void create_thread(std::vector<int>& vint, vecThread& vThr) {
	for (int k = 0; k < vThr.size(); ++k) vThr[k] = std::thread([&]() {++vint[k]; });
};

void join_thread(std::vector<std::thread>& vThreads) {
	for (auto& thr : vThreads) thr.join();
};

int main() {



	wait_;
	return 0;
}




//template<typename T>
//using func = void(*)(T&);
//
//template<typename T, typename ...Ts>
//using Func = void(*)(T&, const Ts&...);
//
//void f(int& x) {
//	++x;
//}
//
//void f2(std::string& str, const char& c) {
//	str.push_back(c);
//}
//
//int main() {
//	
//	std::vector<func<int>> vf;
//	std::vector<Func<std::string, std::string>> vFstr;
//
//	vFstr.push_back(+[](std::string& str, const std::string& add_str) {
//		str = str + add_str;
//		});
//	vFstr.push_back(+[](std::string& str, const std::string& add_str) {
//		str = str.substr(4) + add_str.substr(2);
//		});
//
//	vf.push_back([](int& x) {++x; });
//	vf.push_back([](int& x) {x = 3 * x - 1; });
//
//	int k = 5;
//	std::string str{ "hello..." };
//	std::string vstr[2]{ "good?", "nice" };
//
//	for (auto f : vf) {
//		f(k);
//		print_ << "value of k " << k << end_;
//	}
//	int i{};
//	for (auto f : vFstr) {
//		f(str, vstr[i]); ++i;
//		print_ << "print string : " << str << end_;
//	}
//
//	wait_;
//	return 0;
//}
