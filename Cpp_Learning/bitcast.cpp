#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <bit>


#define end_    '\n'
#define line_   std::cout << "---------------------------------------------------------------------\n"
#define wait_   std::cin.get()
#define print_  std::cout 

using namespace std;
using char4 = char[4];

template<typename ...Ts>
struct Struct;

template<typename T, typename U, typename V >
struct Struct<T,U,V> {
	T l;
	U m;
	V h;
};

template<typename T,typename U>
struct Struct<T, U> {
	T l;
	U h;
};

struct rgb { unsigned char r, g, b, a; };

struct Int4 {
	unsigned char ll, lh, hl, hh;
};

std::ostream& operator << (ostream& os, const rgb& color) {
	os << "[" << (int)color.r << ", " << (int)color.g << " , " << (int)color.b << " , " << (int)color.a ;

	return os;
}
std::ostream& operator << (ostream& os, const Int4& i) {
	os << "[" << (int)i.ll << ", " << (int)i.lh << " , " << (int)i.hl << " , " << (int)i.hh ;

	return os;
}

auto int_to_short(int i) {

	Struct<short, short> dshort = std::bit_cast<Struct<short, short>>(i);

	return std::pair(dshort.l, dshort.h);

}

int main() {

	float f = 3.5f;
	int i = std::bit_cast<int>(f);

	rgb color{ 200,100,50,0 };

	print_ << "float " << f << " to integer  " << i << end_;
	rgb color2 = std::bit_cast<rgb>(f);


	print_ << color2 << end_;
	print_ << std::bit_cast<Int4>(255) << end_;
	print_ << std::bit_cast<int>(color) << end_;
	auto p = int_to_short(257);
	print_ << p.first << " " << p.second << end_;

	wait_;
	return 0;
}

//int main()
//{
//	float f = 0.1234567f;
//	float x = 23.44566f, y = 0.f;
//
//	char c[5] ;
//
////	auto k = std::bit_cast<char4>(x);
//	std::memcpy(c, &f, sizeof(c));
//	c[4] = 0;
//	print_ << "interpret float ot char " << c << end_;
// 
//	memcpy(c,"abcd",4);
//	print_ << "c = " << c << end_;
//
//	memcpy(&y, c, sizeof(y));
//	print_ << " c " << c << " = " << y << end_;
//
//	char c2[5]{};
//
//	memcpy(c2, &y, 4 * sizeof(char));
//	print_ << " c2 " << c << end_ << end_;
//
//	auto i = std::bit_cast<int>(f);
//	auto ii = static_cast<int>(f);
//	auto ci = (int)f;
//
//	print_ << "int static cast : " << ii << end_;
//	print_ << "c casting float to int : " << ci << end_;
//
//	print_ << setprecision(10);
//	print_ << "float is " << f << end_;
//	print_ << "int i " << i << end_;
//
//	print_ << "int i as c cast " << *((int*)&f) << end_;
//
//	while (false) {
//
//	*((int*)&f) += 1;
//	print_ << "float after changing "  << f << end_;
//
//	if (_getch() == 'e')break;
//	}
//
//	cin.get();
//	return 0;
//}