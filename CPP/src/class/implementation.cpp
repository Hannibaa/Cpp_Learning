#include <iostream>
#include <list>
#include "IBase.hpp"

#define end_ '\n'

template<typename Tinterface>
class Context {
	std::list<Tinterface*>  _list;
public:
	void add(Tinterface* ptr) {
		_list.push_front(ptr);
	}
	void remove(Tinterface* ptr) {
		_list.remove(ptr);
	}

	void draw() const {
		for (auto s : _list) s->draw();
	}
};

using CContext = Context<exemple::IDrawable>;

class Circle : public exemple::IDrawable {
	CContext& _context;
	float r;
public:
	Circle(CContext& context, float r)
		: r(r), _context(context)
	{
		this->set_ID();
		_context.add(this);
	}

	void draw() const override {
		std::cout << "Draw Circle radius " << r << " id = " << this->get_id() << end_;
	}

};

class Square : public exemple::IDrawable {
	float width;
	CContext& _context;
public:
	Square(CContext& context,float width)
		: width(width), _context(context)
	{
		this->set_ID();
		_context.add(this);
	}

	void draw() const override {
		std::cout << "Draw Square width " << width << " Id = " << this->get_id() << end_;
	}

};


int main() {
	CContext context;

	Circle c1(context, 10.f), c2(context, 33.f);
	Square s1(context, 1.f), s2(context, 2.f);




	context.draw();
	return 0;

}