#include <iostream>
#include <string>


/* 
*             Author : KADDA Aoues
*             Date   : 27/10/2023
* 
              Make two overloanding functions, that return differente object, 
			  Make two overloanding class member functions, that return two differents object,

*/


int f(float x, std::string str = "") {
	std::cout << "call f(float,string = 0)->int \n";
	return 100;
}




float f(int x, float y) {
	std::cout << "call f(int,flaot)->float \n";
	f(x);
	return 2.5f;
}

double f(int x) {
	std::cout << "call f(int)->double\n";
	return double(x);
}


class Func_Test {

	int x;

public:
	Func_Test(int _x):x{_x}{}
	Func_Test() = default;

	int f(float x, std::string str = "") {
		std::cout << "call f(float,string = 0)->int \n";
		return 100;
	}

	float f(int x, float y) {
		std::cout << "call f(int,flaot)->float \n";
		f(x);
		return 2.5f;
	}

	double f(int x) {
		std::cout << "call f(int)->double\n";
		return double(x);
	}

};


int main() {

	// testing free function ambiguity

	std::cout << f(10, 2.f) << '\n';
	std::cout << f(4.5f, "hi") << '\n';

	// testing class function ambiguity

	Func_Test f1{ 2234 };

	std::cout << f1.f(45);
	std::cout << f1.f(10, 2.3f) << '\n';
	std::cout << f1.f(2.3f, "here") << '\n';

	std::cin.get();
	return 0;
}