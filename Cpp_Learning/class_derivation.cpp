#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

class IA {

public:
	virtual void printing() = 0;

	virtual ~IA() {}
};

class DA {
	std::string _name;
	int         _id;
public:
	DA(const std::string_view name, int id)
		: _name{name}
		, _id{id}
	{}

	std::string get_name() const { return _name; }
	int get_id() const { return _id; }
};

class A : public IA, public DA {
	float    _percent;
public: 
	A(const std::string_view name, int id)
		:DA{name,id}
		, _percent{33.56f}
	{}

	virtual void printing() override  {
		print_ << "the name is    : " << get_name() << end_
			   << "Id             : " << get_id()  << end_
			   << "accessibility  : " << _percent << end_;
	}

};

int main()
{
	A a{ "hello",12313 };

	a.printing();


	std::cin.get();
	return 0;
}