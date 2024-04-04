#include <iostream>
#include <variant>
#include "MyLib/containers.h"
#include "MyLib/Console_Library/escape_code.h"


template<typename Fn, typename ...Ts>
void for_each_pack(Fn func, const Ts& ...ts) {

	(func(ts), ...);
}


int main() {

	Print_(color::Green, "Iterator ") << end_;
	std::vector<int> v;
	for_each_pack([&v](auto vi)
		{ v.push_back(vi); }, 10, 34, 70.55);


	for (auto e : v) print_ << "val : " << e << end_;

	wait_;
	return 0;
}