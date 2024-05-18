#include <iostream>	
#include "MyLib/Console_Library/escape_code.h"

//template<typename T>
//concept Shape_c = requires(T v) {
//	{v.size()} -> std::convertible_to<long>;
//};

struct Rect {
	long length;
	long breadth;
	long size() {
		return length * breadth;
	}
};

//void print_implicit(Shape_c auto& shape) {
//	std::cout << "print implicit : " << shape.size() << '\n';
//}


template<typename Cept, typename Implementor>
struct CeptIsImpl : public std::false_type {};

struct Shape{}; // mystery interface

template<typename T>
concept Shape_c = CeptIsImpl<Shape, T>::value;

template<typename T>
concept ShapeCheck_c = requires(T v) {
	{v.size()} -> std::convertible_to<long>;
};

template<>
struct CeptIsImpl<Shape, Rect> : std::conditional<ShapeCheck_c<Rect>,
	                                              std::true_type,
												  std::false_type>{};

void print_concept(Shape_c auto& shape) {
	std::cout << "print concept " << shape.size() << std::endl;
}

int main() {

	//static_assert(Shape_c<Rect>);

	Rect rect{ 5,5 };

	std::vector<void*> shapes;
	print_concept(rect); print_concept(shapes);


	wait_;
	return 0;
}