#include <iostream>
#include <MyLib/containers.h>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"


using namespace std;

template<typename Class>
class Adaptor {

	void* ptr_;

public:

	Adaptor(const Class& Obj) : ptr_{ (void*) & Obj} {}

	Class* get() {  return (Class*)ptr_;  }

	void free() { ptr_ = nullptr; }

};


int main()
{
	Print_(color::Green, "Stack adaptor for vector test") << end_;

	auto vec = vu::makeRandomContainer<std::vector, int>(1, 10, 10);

	Print_(color::Yellow, "print vector : ") << end_;
	vu::print_container(vec);

	// use adaptor :

	Adaptor ad(vec);

	print_ << " 1.) adress of vector : " << ad.get() << end_;

	Print_(color::Red, "print again vector with pointer adaptor ") << end_;
	vu::print_container(*ad.get());

	ad.free();

	print_ << " 2.) adress of vector : " << ad.get() << end_;

	cin.get();
	return 0;
}