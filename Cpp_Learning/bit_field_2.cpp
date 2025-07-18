#include <iostream>
#include <console/escape_code.h>

/*
	 BIT FIELD  C++
	 AUTHOR : KADDA AOUES
	 DATE   : 25 OCTOBER 2023
*/


struct Float32 {
	union {
		float fValue;
		struct {
			unsigned int mantissa : 23;
			unsigned int exponent : 8;
			unsigned int sign : 1;
		};
	};

	Float32(float f) :fValue(f) {}
};

void Print_EEEI_float(float x) {

	Float32 f{ x };

	print_ << "mantissa : " << f.mantissa << end_;
	print_ << "exponent : " << f.exponent << end_;
	print_ << "sign     : " << f.sign << end_;

}

int main()
{
	Float32 f{ -1.5f };

	Print_EEEI_float(-1.5f);
	Print_EEEI_float(0.f);
	Print_EEEI_float(1.44f);
	Print_EEEI_float(1.45E+10f);


	std::cin.get();
	return 0;
}