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

	Print_(color::Fuchsia, "i64 = ") << std::hex << i64 << end_;
	Print_(color::Green, "Point2d " << std::hex << p1.x << " " << p1.y) << end_;

	print_ << "get second char after second integer in i64 " <<
		(int)getSubType_<char, short>(i64, 2, 1) << end_;


	cin.get();
	return 0;
}