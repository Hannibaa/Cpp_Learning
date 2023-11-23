#include <iostream>
#include <concepts>
#include <functional>
#include <MyLib/containers.h>
#include "MyLib/Console_Library/escape_code.h"


template<typename F>
struct RT {
	using type = decltype(std::declval<F>()());
};


template<typename Container, typename _Function>
	requires requires(typename Container::mapped_type M, _Function f) {
		requires std::invocable<_Function, typename Container::mapped_type>;
		requires std::same_as<decltype(f(M)), decltype(M)>;
}
class ProcessContainer {

	Container*  ptr;
	_Function   function;

	using key_type = Container::key_type;
	using mapped_type = Container::mapped_type;

public:
	ProcessContainer(Container* _ptr, _Function _function)
		: ptr{_ptr},
		  function{_function}
	{}

	std::vector<mapped_type> operator()() {
		std::vector<mapped_type> w;
		for (auto& v : *ptr) {
			w.push_back(function(v.first));
		}

		return w;
	}
};

int f(int x) { return 100 * x; }
float g(int x) { return float(x); }
int h(float x) { return int(x); }

std::string fs(int x) { return std::to_string(x); }

int main()
{
	std::map<int, int>  _m{ {3000, 0},{6000, 4}, {300, 6},{100, 9} };
	std::set<int> _s;


	print_ << "container is map value :\n";
	for (const auto& v : _m)
		print_ << "{" << v.first << "|" << v.second << "} ,";
	print_ << BACKSPACE << ' ' << end_;

	ProcessContainer process(&_m, [](int x) {return 10 * x; });

	auto v = process();

	print_ << "size of v : " << v.size() << end_;
	for (auto& e : v) print_ << e << " ";
	print_ << end_;

	ProcessContainer process1(&_m, h); // h g f ok; fs not 

	auto v2 = process1();

	print_ << "size of v : " << v2.size() << end_;
	for (auto& e : v2) print_ << e << " ";
	print_ << end_;


	std::cin.get();
	return 0;
}