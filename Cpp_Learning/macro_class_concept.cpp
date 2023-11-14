#include <iostream>
#include <vector>
#include <set>
#include <list>
#include "MyLib/Console_Library/escape_code.h"

#define _String(str)   std::string str(#str)
#define _Int(n)        int##n##_t 

#define make_function(func)    std::string  func##(int x) { \
                               return #func + std::to_string(x);} \


make_function(hello0)

#define Class(name) template<typename T>      \
	requires requires(T t) { t + t; }         \
struct name {                                   \
	static void print() { std::cout << " hello "#name << end_; }   \
}         \

//has memnership or member function.
#define REQUERES(_Class, _Type ,_Function)  requires(_Class C,_Type value){ C._Function(value);}

#define MAKE_HAS_FUNCTION(_Class, _Type, _Function) template<typename _Class, typename _Type> \
          concept  Has_##_Function = REQUERES(_Class, _Type, _Function)                        \

#define _CLASS_Member(T,F)   T##::##F 


MAKE_HAS_FUNCTION(Container, T, push_back);

Class(Yes);
Class(Good);

template<typename Container, typename T>
requires Has_push_back<Container,T>
void add(Container& container, const T& value) {
	container.push_back(value);
}


int main()
{
	_String(hello);
	_Int(8) i8 {};
	_Int(16) i16 {};
	Yes<float> y;
	Good<std::string> g;
	Yes<bool> ybool;

	auto kk = _CLASS_Member(std::string, npos);

	y.print();
	Good<int>::print();

	std::vector<int> v;
	std::set<int> s;
	std::list<int> l;

	add(v, 200);
	// add(s, 200); // don't has push_back function
	add(l, 200);


	print_ << hello0(10) << end_;

	std::cin.get();
	return 0;
}