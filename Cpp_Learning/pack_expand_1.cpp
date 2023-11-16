#include <iostream>
#include <MyLib/Console_Library/escape_code.h>
#include "print_pack_names.hpp"


using namespace std;

// Helpers
struct unit {};

struct f_ {
	template<typename...Ts>
	f_(Ts&&...) {}
};

template<typename T>
bool printV(T t)
{
	cout << t << end;
	return true;
}

template<typename ...Ts>
void f(Ts...t) {}

template<class...types>
auto printValue(types&& ...args)
{
	// f((printV(std::forward<types>(args)),0)...);  // first attempt
	// second attempt
	//f( (cout << args << ' ',0)...);
	// third attempt
	f_{ (cout << args << ' ', unit{})... };
	return true;
}

template<typename ...Ts>
void printValue2(Ts...args) {
	int d[] = { (cout << args << " ",0)... };
}

template<typename...Ts>
void printValue3(Ts...args) {
	(cout << ... << args) << "\n";
}

float f(int x) { return (float)x; }

int main()
{

	printValue(20, 'a', "that"s, "Here"s); newline_;
	printValue2(20, 'a', "that"s); newline_;
	printValue3(400, 'c', "Here"s);
	//printPackName(&printValue<int,bool>);
	newline_;
	printPackNames(20, 'a', "that", L"", L"t"s);
	newline_;
	print_ << "print types of class string : " << end_;
	printPackNames(string());

	newline_;

	int i = (f(78), 5);

	cout << " i " << i;

	cin.get();
	return 0;
}