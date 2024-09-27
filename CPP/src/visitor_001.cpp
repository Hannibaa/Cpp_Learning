#include <iostream>
#include <variant>
#include <functional>
#include <vector>

#define print_   std::cout 
#define end_	 '\n'

class Int {
	int i;
public:

	explicit Int(int i):i(i){ }

	int& operator()(int _i) {
		i = _i;
		return i;
	}

	int operator()() const {
		return i;
	}

};

struct Float {
	float f;
public :

	explicit Float(float f) : f(f) {}

	float& operator()(float _f) {
		f = _f;
		return f;
	}

	float operator()() const {
		return f;
	}

};

struct Char {

	explicit Char(char i) :i(i) { }

	char& operator()(char _i) {
		i = _i;
		return i;
	}

	char operator()() const {
		return i;
	}
private:
	char i;
};

using Number = std::variant<Int, Float, Char>;

class Visitor {
public:
	void operator() (Int i) {
		print_ << "integer version ";
		print_ << " n = " << i() << end_;
	}

	void operator()(Float f){
		print_ << "float version   ";
		print_ << " n = " << f() << end_;
	}
};

class VisitorTemp {
public:
	template<typename T>
	void operator()(T x) {
		print_ << "type " << typeid(T).name() << end_;
		print_ << "value : " << x() << end_;
	}
};


int main() {

	std::vector<Number> numbers;

	numbers.push_back(Int(34));
	numbers.push_back(Float(3.12f));
	numbers.push_back(Int(4445));
	numbers.push_back(Float(23.f));
	numbers.push_back(Char('k'));
	numbers.emplace_back(Float(20.f));
	//numbers.emplace_back(66);
	//numbers.emplace_back(55);
	//numbers.emplace_back(0.0001f);

	//for(auto& e : numbers )
	//std::visit(Visitor{}, e);

	print_ << end_ << end_ << "Second implementation \n";

	for (const auto& e : numbers)
		std::visit(VisitorTemp{}, e);

	return 0;
}