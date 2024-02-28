#include <iostream>
#include <MyLib/Console_Library/escape_code.h>

#include <vector>

class Console {

};

class Shape {
	std::reference_wrapper<Console>  _console;
	float x;
	float y;
	float v;

public:

	Shape(Console& console, float x, float y, float v)
		: _console(console), x(x), y(y) , v(v) 
	{}

	Shape(Console& console) : Shape(console,0.f,0.f,0.f) {}

};

int main() {

	Console console;

	std::vector<Shape>  vec;

	vec.emplace_back(console, 10.f, 10.f, 5.f);

	vec.emplace_back(console, 3.f, 5.f, 1.1f);

	print_ << "size of vector " << vec.size() << end_;

	vec.erase(vec.begin()+ 1);

	print_ << "size of vector " << vec.size() << end_;


	print_ << "End...\n";

	wait_;
	return 0;
}
