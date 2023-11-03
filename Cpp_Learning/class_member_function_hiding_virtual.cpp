#include <iostream>
#include "MyLib/Console_Library/escape_code.h"


class Base {
	int x;
public:
	virtual/* remove virtual and see dif*/ int get() const { print_ << "Base get() \n"; return x; }
	void set(int _x) { print_ << "Base set() \n"; x = _x; }
};

class Derived : public Base {

public:
	int get() const { print_ << "Derived get() \n"; return 100; }

};

int get(Base b) {
	return b.get();
}

int get(Base* ptr_b) {
	return ptr_b->get();
}

int get_ref(const Base& ref_b) {
	return ref_b.get();
}


int main()
{
	Base b{};
	auto i = b.get();
	b.set(34);

	Derived d{};
	auto j = d.get();
	d.set(44);

	newline_;
	print_ << "get(base) : " << get(b) << end_;
	print_ << "get(derived)  " << get(d) << end_;

	newline_;
	// polymorphic we use pointer is better?
	print_ << "test pointer version \n";
	print_ << "get(base) : " << get(&b) << end_;
	print_ << "get(derived) : " << get(&d) << end_;
	newline_; 
	print_ << "test const reference version \n";
	print_ << "get(base) : " << get_ref(b) << end_;
	print_ << "get(derived) : " << get_ref(d) << end_;


	std::cin.get();
	return 0;
}