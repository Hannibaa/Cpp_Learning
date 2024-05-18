#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

// class X
class X {
public:
	int _x;
	X(): _x{10}{}
	X(int i):_x{i}{}
};

// interface Cx
class Cx {
	X mem;
public:
	virtual X& f() = 0;

	X& _X() { return mem; }
};

// derived class
class DA : public Cx {
public:
	X& f() {
		return _X();
	}

};

class DB : public Cx {		// derived class
	DB* p;					// representation can be more extensive than what the base provides
public:
	X& f() {
		return _X();
	}
	void k(int x) {
		x = x + 1;
		p->_X()._x += x + this->_X()._x;
	}             // add functionality
};


int main() {

	Cx& rcxa{ *new DA };
	Cx& rcxb{ *new DB };

	wait_;
	return 0;
}