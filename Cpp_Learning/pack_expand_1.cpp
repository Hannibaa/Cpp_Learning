#include <iostream>
#include "print_pack_names.hpp"

#define end '\n'
#define Line cout << "---------------------------------------------\n"

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

	printValue(20, 'a', "that"s, "Here"s); Line;
	printValue2(20, 'a', "that"s); Line;
	printValue3(400, 'c', "Here"s);
	//printPackName(&printValue<int,bool>);
	Line;
	printPackNames(20, 'a', "that", L"", L"t"s);
	Line;
	printPackNames(string());
	Line << end;

	int i = (f(78), 5);

	cout << " i " << i;

	cin.get();
	return 0;
}