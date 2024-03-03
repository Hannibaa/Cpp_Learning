#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

/*
       VISITOR PATTERN
*/

#define __exemple_4



//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    MODERN C++ SOLUTION OF VISITOR PATTERN : STD::VARIANT
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __exemple_4
// A Modern C++ Solution
#include <variant>

class Circle {
public:
	explicit Circle(float r)
		: radius{r}
	{}

	float getRadius() const noexcept {
		return radius;
	}

private:
	float radius;
};

class Square {
public:
	explicit Square(float s)
		:side{s}
	{}

	float getSide() const noexcept {
		return side;
	}

private:
	float side;
};


class Draw {
public:
	void operator()(Circle const& c) const{
		print_ << "Draw Circle... of Radius :" << c.getRadius() << end_;
	}

	void operator()(Square const& c) const {
		print_ << "Draw Square... of Side : " << c.getSide() << end_;
	}
};

using Shape = std::variant<Circle, Square>;

void drawAllShapes(std::vector<Shape> const& shapes) {
	for (const auto& s : shapes) {
		std::visit(Draw{}, s);
	}
}


int main() {
	using Shapes = std::vector<Shape>;
	
	// Creating some shpes
	Shapes shapes;
	shapes.emplace_back(Circle{ 2.5f });
	shapes.emplace_back(Square{ 10.f });
	shapes.emplace_back(Circle{ 3.0f });
}


#endif // __exemple_4





//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    C++ VISITOR DESIGN PATTERN ;
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __exemple_3
// The Design Pattern Solution -- Visitor --
class Circle;
class Square;

class ShapeVisitor {
public:
	~ShapeVisitor() = default;

	virtual void visit(Circle const&) const = 0;
	virtual void visit(Square const&) const = 0;
};

class IShape {
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual void accept(ShapeVisitor const& ) = 0;
	// PROBLEM TO ADD VIRTUAL FUNCTIONS
	/*
	* 
	* 
	*/

};

class Circle : public IShape {
public:
	explicit Circle(float rad)
		: radius{ rad }
		//, ...Remainin data members
	{}

	float getRadius() const noexcept {
		return radius;
	}
	// ... other methodes getCenter(), getRotation, move() ...

	void accept(ShapeVisitor const& sv) override {
		sv.visit(*this);
	};

private:
	float radius;
	// .... ramaining data members
};


class Square : public IShape {
public:
	explicit Square(float s)
		: side{ s }
	{}

	float getSide() const noexcept {
		return side;
	}
	// ... getCenter, getRotation()...

	void accept(ShapeVisitor const& vs) override {
		vs.visit(*this);
	}

private:
	float   side;
	// ... another data members
};


class Draw : public ShapeVisitor {
public:
	void visit(Circle const& c) const override {
		print_ << "draw Circle..." << "diameter : " << c.getRadius() << end_;
	}
	void visit(Square const& s) const override {
		print_ << "draw Square..." << "side : " << s.getSide() << end_;
	}
};

class Move : public ShapeVisitor {
public:
	void visit(Circle const& c) const override {
		Print_(color::Green, "Move Circle") << end_;
	}

	void visit(Square const& s) const override {
		Print_(color::Red, "Move Square") << end_;
	}
};

void drawAllShapes(std::vector<std::unique_ptr<IShape>> const& shapes) {
	for (auto const& s : shapes) {
		s->accept(Draw{});
	}
}


int main() {

	using Shapes = std::vector<std::unique_ptr<IShape>>;

	// Creating some shapes
	Shapes shapes;
	shapes.emplace_back(std::make_unique<Circle>(2.0f));
	shapes.emplace_back(std::make_unique<Square>(1.23f));
	shapes.emplace_back(std::make_unique<Circle>(4.4f));

	// draw all shipe
	drawAllShapes(shapes);

	// Move circle
	shapes[0]->accept(Move{});
	shapes[1]->accept(Move{});

	wait_;
	return 0;
}

#endif // __exemple_3


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    OBJECT ORIENTED SOLUTION
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __exemple_2
//   Object-Oriented Solution

class IShape {
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual void draw(/* ...*/) const = 0;
	// PROBLEM TO ADD VIRTUAL FUNCTIONS
	/*
	virtual void serialize() const = 0;
	virtual void translate(float x, float y) = 0;
	virtual void rotate(float const& f) = 0;
	 Changing interfaces in OOP is difficult!
	 OOP is the WRONG choice if you need to add operation?
	*/

};

class Circle : public IShape {
public:
	explicit Circle(float rad)
		: radius{ rad }
		//, ...Remainin data members
	{}

	float getRadius() const noexcept;
	// ... other methodes getCenter(), getRotation, move() ...

	void draw() const override;

private:
	float radius;
	// .... ramaining data members
};


class Square : public IShape {
public:
	explicit Square(float s)
		: side{ s }
	{}

	float getSide() const noexcept;
	// ... getCenter, getRotation()...

private:
	float   side;
	// ... another data members
};

void drawAllShapes(std::vector<std::unique_ptr<IShape>> const& shapes) {
	for (auto const& s : shapes) {
		s->draw();
	}
}

int main() {

	using Shapes = std::vector<std::unique_ptr<IShape>>;

	// Creating some shapes
	Shapes shapes;
	shapes.emplace_back(std::make_unique<Circle>(2.0f));
	shapes.emplace_back(std::make_unique<Square>(1.23f));
	shapes.emplace_back(std::make_unique<Circle>(4.4f));

	// draw all shipe
	drawAllShapes(shapes);


	wait_;
	return 0;
}




#endif // __exemple_2





//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    First Designe
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __exemple_1
// Precedural Solution

enum ShapeType {
	circle,
	square   // PROBLEM if we add rectangle
};

class IShape {
public:
	explicit IShape(ShapeType t) : type{ t } {}

	virtual ~IShape() = default;
	ShapeType getType() const noexcept;

private:
	ShapeType type;
};

class Circle : public IShape {
public:
	explicit Circle(float rad)
		:IShape{circle}
		,radius{rad}
	{}

	float getRadius() const noexcept;
	// ... other methodes getCenter(), getRotation, move() ...

private:
	float radius;
	// .... ramaining data members
};

void translate(Circle&, float x, float y);
void rotate(Circle&, float const&);
void draw(Circle const&);

class Square : public IShape {
public :
	explicit Square( float s)
		:IShape{ square }
		, side{s}
	{}

	float getSide() const noexcept;
	// ... getCenter, getRotation()...

private:
	float   side;
	// ... another data members
};

void drawAllShapes(std::vector<std::unique_ptr<IShape>> const& shapes) {
	for (auto const& s : shapes) {
		switch (s->getType())
		{
		case circle: draw(*static_cast<Circle const*>(s.get()));
			break;
		case square: draw(*static_cast<Square const*>(s.get()));
			break;
		default:
			break;
		}
	}
}

int main() {

	using Shapes = std::vector<std::unique_ptr<IShape>>;

	// Creating some shapes
	Shapes shapes;
	shapes.emplace_back(std::make_unique<Circle>(2.0f));
	shapes.emplace_back(std::make_unique<Square>(1.23f));
	shapes.emplace_back(std::make_unique<Circle>(4.4f));

	// draw all shipe
	drawAllShapes(shapes);
	

	wait_;
	return 0;
}

#endif