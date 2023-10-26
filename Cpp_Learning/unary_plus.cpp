#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"


using namespace std;


int main()
{
	char c = 66;
	int  i = -77;
	float f = 4.5f;
	double d = 5.7767;
	long long int li = 4454545i64;

	long double ld = 55.44L;

	auto k_c = +c; print_ << "type is " << typeid(k_c).name() << end_;
	auto k_i = +i; print_ << "type is " << typeid(k_i).name() << end_;
	auto k_f = +f; print_ << "typen is " << typeid(k_f).name() << end_;


	cin.get();
	return 0;
}