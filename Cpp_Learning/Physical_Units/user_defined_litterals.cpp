#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

enum unite {
	psi, pascal , bar  
};

template<unite  _U>
class Pressure {
	float   pressure;
public:
	Pressure(float pr): pressure{pr}{}

	operator float () const {
		return pressure;
	}
};


Pressure<psi> operator""_psi(long double pr) {
	return Pressure<psi>(pr);
};


int main() {

	Pressure<psi>  pr = 100.f;

	Pressure prA = pr ;

	Pressure Pt0 = 3000.34_psi;

	auto p = pr + prA;

	auto p2 = 300.f + pr;

	print_ << p << " , " << p2 << end_;

	print_ << pr << " , " << prA << end_;

	wait_;
	return 0;
}