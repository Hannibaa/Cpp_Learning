// in this exemple we will expose strategy

#include <iostream>
#include <cmath>

#define print_ std::cout
#define end_   '\n'

class ICircFunc {

public:

	virtual float f(float) = 0;

	virtual ~ICircFunc() = default;
};



class Object {
	float x;
	ICircFunc* circular_func;
public:

	Object(float init_x, ICircFunc* function)
		:x(init_x),
		 circular_func(function)
	{}

	void set_value(float _x) {
		x = _x;
	}

	void set_function(ICircFunc* function) {
		circular_func = function;
	}

	float transform() {
		return circular_func->f(x);
	}

};

class Sinus :public ICircFunc{
public:
	float f(float x) {
		return std::sin(x);
	}
};

class Cosin : public ICircFunc {
public:
	float f(float x) {
		return std::cos(x);
	}
};

class Tangent : public ICircFunc {
public:
	float f(float x) {
		return std::tan(x);
	}
};


int main() {

	Cosin cos;

	Object obj(23.f, &cos);
	
	print_ << obj.transform() << end_;

	float x1 = obj.transform();

	Sinus sin;

	obj.set_function(&sin);

	print_ << obj.transform() << end_;

	float x2 = obj.transform();

	print_ << x1 * x1 + x2 * x2 << end_;


	return 0;
}



