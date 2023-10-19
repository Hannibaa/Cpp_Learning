#include <iostream>
#include <string>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"

using namespace std::literals;

template<typename X>
struct T {
	X x;
	friend std::ostream& operator << (std::ostream& os, const T& x) {
		os << x.x;
		return os;
	}
};

struct X {

	float x;

	friend std::string to_string(const X& x) {
		return "X to_string function hiden in X";
	}

	friend int getXX(X _x) { return static_cast<int>(_x.x); }
};

template<typename T>
struct Point {
	T x, y;
	Point(T _x = T{}, T _y = T{}) : x{ _x }, y{ _y } {}

	friend std::string to_string(const Point& p) {
		return std::to_string(p.x) + " "s + std::to_string(p.y);
	}
};


int main()
{
	print_ << " T{} " << T{ 4 } << end_;

	X y;

	print_ << "std::to_string " << std::to_string(3453534) << end_;
	print_ << "X hiden function to_string " << to_string(y) << end_;

	Point p(3.5, 6.7);

	print_ << to_string(p) << end_;

	print_ << "float to int " << getXX(X(4.66)) << end_;
	print_ << "float to int " << getXX(X(44)) << end_;

	std::cin.get();
	return 0;
}