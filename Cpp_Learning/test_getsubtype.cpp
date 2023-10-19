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

	int i32 = 0x0f1f'2f3f;

	Print_(color::Red, "---- THIS PROGRAM FOR TESING FUNCTION getSubType ----") << end_;
	Print_(color::Green, "Point2d " << std::hex << p1.x << " " << p1.y) << end_;

	print_ << "we get 1 short of Point p1 " << getSubType_<short, short>(p1, 0) << end_;
	print_ << "we get 2 short of Point p1 " << getSubType_<short, short>(p1, 1) << end_;
	print_ << "we get 3 short of Point p1 " << getSubType_<short, short>(p1, 2) << end_;
	print_ << "we get 3 short of Point p1 " << getSubType_<short, short>(p1, 3) << end_;
	print_ << "we get 4 short of Point p1 " << getSubType_<short, short>(p1, 4) << end_;  // will not give you any thing

	//Print_(color::Green, "i64 = " << std::hex << i64) << end_;
	//print_ << "we get 1 int of i64 " << getSubType_<int,int>(i64,0) << end_;
	//print_ << "we get 2 int of i64 " << getSubType_<int,int>(i64,1) << end_;
	//print_ << "we get 3 int of i64 " << getSubType_<int,short>(i64,2) << end_;


	cin.get();
	return 0;
}