#include <iostream>
#include <MyLib/containers.h>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"


using namespace std;

template<typename Class>
class Adaptor {

	void* ptr_;

public:
	
	Adaptor(const Class& Obj) : ptr_{ &obj } {}

	void* get() { return ptr_; }

};


int main()
{
	Print_(color::Green, "Stack adaptor for vector test") << end_;

	auto vec = vu::makeRandomContainer<vector, int>(0, 100, 10);
	
	Print_(color::Red, "Vec ") << end_;
	vu::print_container(vec);

	newline_;

	std::stack S(vec);

	S.push(300);

	Print_(color::Red, "Vec ") << end_;
	vu::print_container(vec);
	newline_;

	Print_(color::Green, "S : ") << end_;
	print_ << "Stack top " << S.top() << end_; S.pop(); S.push(400);

	print_ << "Stack top " << S.top() << end_;

	cin.get();
	return 0;
}