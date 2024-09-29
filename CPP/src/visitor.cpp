#include <iostream>

template<typename T1, typename T2>
class IFunctions {

public:

	virtual void function(const T1&) = 0;
	virtual void function(const T2&) = 0;

};

class Object1;
class Object2;

// make a visitor function from object
using Visitor = IFunctions<Object1, Object2>;

class IObject {
public:
	virtual void accept(Visitor*) = 0;
};

class Object1: public IObject {
public:
	void accept(Visitor* v) {
		v->function(*this);
	}
};

class Object2 : public IObject {
public:
	void accept(Visitor* v) {
		v->function(*this);
	}
};


class Visitor1 : public Visitor {
public:
	void function(const Object1& obj) {
		std::cout << " Object 1 drawing\n";
	}

	void function(const Object2& obj) {
		std::cout << " Object 2 drawing\n";
	}
};





int main() {

	Object1 ob1;
	Object2 ob2;

	Visitor1 v;

	ob1.accept(&v);

	ob2.accept(&v);


	return 0;
}