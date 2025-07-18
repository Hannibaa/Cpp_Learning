#include <Windows.h>
#include <iostream>

#define end_ '\n'

// define concepts
template<typename Coordinate>
concept has_XY = requires(Coordinate coord) {
	coord.X; coord.Y;
};


template<typename Vec>
requires has_XY<Vec>
Vec make_vector(Vec& v) {
	std::cout << "call with concepts\n";
	v.X = 200;
	v.Y = 300;

	return v;
}

template<typename Vec>
Vec make_vector(Vec& v) {
	std::cout << "call without concepts\n";
	v.x = 400;
	v.y = 500;

	return v;
}

template<typename T>
struct Vector {
	T x;
	T y;

	Vector() {}

	template<typename Coord>
	requires has_XY<Coord>
	Vector(const Coord& coord)
		: x(coord.X), y(coord.Y)
	{}

};

int main() {

	COORD   P{ .X = 100, .Y = 200 };
	Vector<int> V;

	Vector<int>  W = P;

	Vector<int> Z = V;

	make_vector(P);

	std::cout << P.X << ", " << P.Y << end_;

	make_vector(V);

	std::cout << V.x << ", " << V.y << end_;

	std::cout << W.x << ", " << W.y << end_;

	std::cin.get();
	return 0;
}
