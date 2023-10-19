#include <iostream>

#define end_    '\n'
#define line_   std::cout << "---------------------------------------------------------------------\n"
#define wait_   std::cin.get()
#define print_  std::cout 

using namespace std;

class Function {
	float f;

public:
	Function(float x) :f{ x } {}

	Function& operator()(float y) { f *= y; return *this; }

	float value() const { return f; }
};

int _l{};

class Action {
public:
	Action() = default;
	Action(std::string str, int& l) {
		static int length{};

		length += str.length();

		l = length;

		print_ << "length " << length << end_;
	}
};


int main() {
	int k{};
	Action a("hello", _l);
	Action b("this", k);
	Action c;

	print_ << _l << " " << k << end_;

	//print_ << " l " << _l << end_;
	//Action::Action("Hello",_l);
	//print_ << " l " << _l << end_;

	//Action::Action("world", _l);
	//print_ << " l " << _l << end_;

	wait_;
	return 0;
}


//int main()
//{
//	Function f(4.5f);
//
//	print_ << f(2.f).operator()(2).operator()(1.f).value()<< end_;
//
//	cin.get();
//	return 0;
//}