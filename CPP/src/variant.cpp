#include <iostream>
#include <vector>
#include <variant>

class IShape {
public:
	virtual void draw() const = 0;

	virtual ~IShape() = default;
};

class Circle : public IShape {
	float r;
public:
	explicit Circle(float _r = 0.f) : r(_r) {}

	void set_radius(float _r) { r = _r; }

	auto get_radius() const { return r; }

	void draw() const override {
		std::cout << "Draw Circle of radius " << r << " end\n";
	}

};

class Square : public IShape {
	float a;

public:
	explicit Square(float _a) : a(_a) {}

	void set(float _a) { a = _a; }

	auto get() const { return a; }

	void draw() const override {
		std::cout << "Draw Square of long " << a << " end\n";
	}
};

using Shape = std::variant<Circle, Square>;


class Move {
	float speed{0.1f};

public:

	void set_speed(float _speed) {
		speed = _speed;
	}

	void operator()(Circle& c) {
		std::cout << "move circle with speed " << c.get_radius() << "|" << speed << " end\n";
	}

	void operator()(Square& s) {
		std::cout << "move square with speed " << s.get() << "|" << speed << " end\n";
	}
};


int main() {

	Move move;
	move.set_speed(1.1f);

	Circle c1(3.4f);
	Square s1(4.6);

	std::vector<Shape>  shapes;

	shapes.push_back(c1);
	shapes.push_back(s1);
	shapes.emplace_back(Circle(4.6f));
	shapes.emplace_back(Square(5.5f));

	for (auto& e : shapes)
		std::visit(move,e);


	return 0;
}