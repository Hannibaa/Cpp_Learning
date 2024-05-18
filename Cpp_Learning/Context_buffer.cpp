#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include <vector>
#include <any>


class Context {
	std::vector<std::any>       v_;
public:
	Context() = default;

	template<typename T>
	Context(const T& t) {
		v_.push_back(t);
	}

	template<typename T>
	void push_back(const T& t) {
		v_.push_back(t);
	}

	size_t size() const {
		return v_.size();
	}

	auto operator()(int i) {
		return v_[i];
	}
};

class String : public std::string {
public:
	using std::string::basic_string;

	String(Context& context) {
		context.push_back(*this);
	}
};


int main() {
	Print_(color::Green, "Making constructor that store object already constructed to context") << end_;
	
	Context  ctx;

	ctx.push_back(23424);
	ctx.push_back(std::string("hello"));
	ctx.push_back(4.f);

	String string(ctx);

	string = "hello new string";

	print_ << "size of vector is : " << ctx.size() << end_;
	print_ << "this one is : " << ctx(0).has_value() << end_;
	print_ << "value by any cast " << std::any_cast<int>(ctx(0)) << end_;
	print_ << "value by any cast " << std::any_cast<String>(ctx(3)).c_str() << end_;


	Print_(color::Red, "End of program") << end_;
	wait_;
	return 0;
}