#include <iostream>

template<int (*F)(float)>
int func(float x) {
	return F(x);
}

template< auto F>
int func2(auto x) {
	return F(x);
}

template<struct T>
struct M {

};

struct T {
	int i;
};


int main() {
	std::cout << "Describ Template Parameter Function, or Lambda \n";

	std::cout << "value : " << func < +[](float x) {return int(x); } >(34.f) << "\n";

	func2 < +[](float x) {return int(x); } > (300);
	func2 < +[](std::string x) {return int(x.size()); } > ("hello");

	M < T{ 0 } > m;

	std::cin.get();
	return 0;
}