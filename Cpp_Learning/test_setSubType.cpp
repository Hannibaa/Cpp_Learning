#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include "getsubtype.h"


using namespace std;


template<typename T>
struct Point2d {
	T x;
	T y;
};

template <typename T>
struct Point3d {
	T x, y, z;
};

int main()
{
	uint64_t i64 = 0xf8f7'f6f5'f4f3'f2f1;

	Point2d<int>  p1{ .x = (int)0xa4a3'a2a1, .y = (int)0xb4b3'b2b1 };

	int i32 = 0xe4e3'e2e1;

	Print_(color::Red, "---- THIS PROGRAM FOR TESING FUNCTION setSubType ----") << end_;
	Print_(color::Green, "Point2d " << std::hex << p1.x << " " << p1.y) << end_;

	print_ << "set number i32 inside i64 after 1 byte  " << setSubType(i32, i64, 3) << end_;
	print_ << "set number char inside i32 after 2 byte " << setSubType((char)0xdd, i32, 2) << end_;
	setSubType(i32, p1, 0);
	print_ << "in struct pointer we change first int    " << p1.x << " " << p1.y << end_;
	setSubType(0xccaaccaa, p1, 4);
	print_ << "in struct pointer we change second int   " << p1.x << " " << p1.y << end_;

	// check over flow
	setSubType((int)12345, p1, 5);
	print_ << "in struct pointer we check overflow int   " << p1.x << " " << p1.y << end_;



	cin.get();
	return 0;
}