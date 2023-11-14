#include <iostream>
#include <string>
#include "MyLib/headers/my_concepts.h"
#include "MyLib/Console_Library/escape_code.h"

using namespace std::literals;


template<typename T>
requires Concept::Post_Incrementable<T>
struct Point {
	T x, y;
	Point() :x{}, y{}{}
	Point(T x, T y = T{}) :x{ x }, y{ y } {}

	Point operator++(int) {Point tempPoint = *this ; ++x; ++y; return tempPoint; }
};


template<typename T, size_t N>
	requires Concept::SizeOf<T,4>
T inc_function() {
	static T i{};
	return i++;
}


int main()
{
	print_ << "value : " << inc_function<int, 0>() << end_;
	//print_ << "value : " <<  inc_function<char, 0>()            << end_;
	//print_ << "value : " <<  inc_function<unsigned char, 0>()   << end_;
	//print_ << "value : " <<  inc_function<short, 0>()		    << end_;
	//print_ << "value : " <<  inc_function<double, 0>()		    << end_;
	print_ << "value : " <<  inc_function<Point<short>, 0>().x    << end_;


	std::cin.get();
	return 0;
}