#include <iostream>
#include <vector>
#include <sstream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/random_variable.h"

//class Text {
//
//	std::wstring    text;
//	RV::SRV<float>  x, y;
//	color           _color;
//
//public:
//
//	//Text(float _x0, float _y0, float _s1, float _x1, float _y1, float _s2, int clr)
//	//	:text{},
//	//	x{ _x0,_y0,_s1 },
//	//	y{ _x1,_y1,_s1 },
//	//	_color{ static_cast<color>(clr) }
//	//{}
//	Text(int _i) : _color{static_cast<color>(_i)} {}
//
//	Text() : Text(5) {}
//	Text(const Text&) = default;
//	~Text() = default;
//
//	void setStarValue(float a, float b) {
//	}
//
//	void setText(std::wstring_view _text) {
//		text = _text;
//	}
//
//	std::wstring update() {
//		std::wstringstream str;
//		int _x = 10; int _y = 10;
//		str << MOVETO(_x, _y) << _wCOLOR_FG256(_color) << text << RESETMODE;
//		return str.str();
//	}
//
//	operator std::wstring() noexcept {
//		return update();
//	}
//};

class A {
	float f;
public:
	A(float f) :f{ f } {}
	A() : A(1.f) {}

	A(const A&) = delete; // this result error C2280 : attempting to reference a deleted function.
};



class Text {
	int i;
	static A a;
public:
	Text(int a) : i{ a } {}

	int update() {
		return i;
	}
};

A Text::a ;


int main()
{
	std::vector<Text> vstr;
	for (int k = 0; k != 7; ++k) {

		vstr.push_back(Text( 10 *k + 10));
		
	}



	newline_;
	print_ << "the list is : " << end_;
	for (auto& s : vstr) print_ << s.update() << end_;

	std::cin.get();
	return 0;
}