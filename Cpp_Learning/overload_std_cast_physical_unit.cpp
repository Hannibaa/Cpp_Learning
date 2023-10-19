#include <iostream>
#include <ratio>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"

#define Length(unit, Num, Den)  using unit = std::ratio<Num,Den>

using namespace std;

enum class lu { meters ,cmeter ,kmeter  };

using M = std::ratio<1, 1>;
using Km = std::ratio<1, 1000>;
Length(Dm, 10, 1);
using Cm = std::ratio<100, 1>;
using Mm = std::ratio<1000, 1>;


struct length {
	float l;

	length() : l{}{}
	length(float _l) : l{_l}{}
	
};

struct meter {
	float m;

	meter() :m{}{}
	meter(float _m):m{_m}{}
	meter(length _l):m{_l.l}{}

	template<typename Ratio>
	float value() const {
		//static_assert(std::is_same_v<Ratio, typename std::ratio>, "Ratio should be ratio");
		return m * static_cast<float>(Ratio::num) / static_cast<float>(Ratio::den);
	}

	operator float() {
		return value<std::ratio<1>>();
	}
};


 meter operator"" _m(long double _l) {
	return meter(static_cast<float>(_l));
}

 meter operator"" _cm(long double _l) {
	 return meter(static_cast<float>(_l) / 100.f);
 }

 meter operator"" _km(long double _m) {
	 return meter(static_cast<float>(_m) * 1000.f);
 }


int main()
{
	print_ << GREEN_BG << "      "<< RESETMODE
		<< GREEN_FG << " test overloading cast and casting unit " << RESETMODE << end_;

	meter l(34.55f);

	l = 234.34_m;

	print_ << "default length is " << l.m << end_;
	print_ << "default length is " << l.value<Dm>() << end_;
	cin.get();
	return 0;
}