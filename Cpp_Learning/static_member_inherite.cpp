#include <iostream>
#include <Windows.h>
#include <include/console/escape_code.h>
#include <include/random/random_generator.h>

template<typename T>
class IDrawable {
	static T x;
	static size_t _id;
public:

	virtual ~IDrawable() = default;

	virtual void draw() const = 0;

	void set_id() {
		_id = rng::Random::rand();
	}

	void get_id() {
		Print_(color::Red, _id) << end_;
	}
};

template<typename T>
size_t       IDrawable<T>::_id;



template<typename T>
class ISprite : public IDrawable<T> {

public :
	virtual ~ISprite() = default;

	virtual void set_rectangle(T, T, T, T) = 0;
};


class Sprite : public ISprite<int> {
	std::string _shape;
public:
	Sprite(const std::string& shape)
		:_shape(shape)
	{}

	virtual void set_rectangle(int x, int y, int dx, int dy)
	{
		Print_(color::Yellow, "rectangle set it") << end_;
	}

	virtual void draw() const {
		Print_(color::Blue, _shape);
	}
	
	~Sprite() = default;
};

class Square : public IDrawable<int> {

public:
	void draw() const override {
		Print_(color::Green, "Square") << end_;
	}

	void set_rectangle(int, int, int, int) {
		Print_(color::Red, "set rect Square") << end_;
	}
};

int main() {

	Print_(color::Green, "Test Some Inheritance") << end_;

	Sprite  sprite("|---<>---|");
	sprite.set_id();
	sprite.set_rectangle(20, 3, 3, 3);
	sprite.draw(); sprite.get_id();

	Square square;

	square.draw();
	square.get_id();
	square.set_id();

	square.get_id();
	sprite.get_id();
	return 0;
}