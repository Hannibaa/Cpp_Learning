#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

struct Point {
private:
	float x, y;
public:
	Point() :Point(0.f,0.f){}
	Point(float _x, float _y) : x{_x},y{_y}{}

	//operator std::pair<float, float>() {
	//	return std::make_pair(x, y);
	//}

	operator float() {
		puts("conversion operator to flaot call");
		return x * y;
	}
		
};

int main()
{
	Point p1, p2(23.f, 45.f);

	auto p = p1;

	std::cout << p2 << end_;



	wait_;
	return 0;
}



// two operator of co
//struct Int {
//	int i{};
//
//	operator int*() {
//		print_ << "call int*\n";
//		return &i;
//	}
//
//	operator void* () {
//		print_ << "call void*\n";
//		return this;
//	}
//};
//
//int main() {
//
//	Int l;
//	l.i = 300;
//
//	print_ << "adress of " << l.i << end_;
//	print_ << "adress of " << l << end_;
//
//	print_ << "int * cast " << l.operator int* () << end_;
//
//	wait_;
//	return 0;
//}








//struct Int {
//	operator int() { 
//		static int x{};
//		return ++x;
//	}
//};
//
//int main()
//{
//	Int x; 
//	Int y;
//
//	print_ << "x is " << x << end_;
//	print_ << "x is " << x << end_;
//	print_ << "y is " << y << end_;
//
//
//	cin.get();
//	return 0;
//}