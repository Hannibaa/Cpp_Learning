#include <iostream>
#include "vectorial.hpp"

#define end_ '\n'

template<typename T>
struct point2d {
	T x;
	T y;

	using value_type = T;
};


int main() {

	auto n = vector::Norm(point2d(1.f, 1.f));

	std::cout << "norm : " << n << end_;

	return 0;
}