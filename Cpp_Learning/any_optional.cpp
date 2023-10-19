#include <iostream>
#include <random>
#include <any>
#include <optional>
#include <fstream>

#define end_ '\n'
#define Line std::cout << "---------------------------------------------------------------------\n"
#define wait_ std::cin.get()
#define print std::cout 

using namespace std;

int random(int range = 100) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> intdis(0, range);

	return intdis(gen);
}

int f1(int x) { return 2 * x + 1; }
int f2(int x) { return 2 * x; }


class F {

	int (*f)(int);

public:
	F(int(*_f)(int)) :f(_f){}

	int operator ()(int x) {
		return f(x);
	}
};

int main()
{
	optional<int(*)(int)> function;

	optional<F> f;

	f = F{f2};

	if(f)
	print << "optional<F> " << f.value()(100) << end_;

	if (random() < 30) function = f1;

	if (function) {
		print << function.value()(100) << end_;
	}
	else
		print << function.value_or(f2)(100) << end_;




	cin.get();
	return 0;
}



//int main()
//{
//	optional<string> opt_str;
//
//	int i_max = 10;
//
//	for (int i = 0; i < i_max; i++) {
//		int r = random();
//		if (r < 25) {
//			opt_str = "here";
//		}
//	        print << r << end_;
//
//
//	        if (opt_str) {
//	        	print << opt_str.value() << end_;
//	        }
//	        else {
//	        	print << opt_str.value_or("not value") << end_;
//	        }
//
//			opt_str.reset();
//	}
//
//
//
//
//	cin.get();
//	return 0;
//}