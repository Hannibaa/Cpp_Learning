#include <iostream>
#include <array>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"

template<int I>
	requires (I > 0)
void func() {
	print_ << "integer positive " << I << end_;
}

template<int I>
requires (I < 0) 
void func() {
	print_ << "integer negative " << I << end_;
}

template<int I>
requires ( I == 0)
void func() {
	print_ << "integer is null " << I << end_;
}

template<auto X>
requires std::is_floating_point_v<decltype(X)>
void func() {
	print_ << "is floating point " << X << end_;
}

template<typename T>
requires std::is_array_v<T>
void func(const T& x) {
	print_ << "is array " << end_;
}

int main()
{
	func<33>();
	func<-44>();
	func<0>();

	func<33.3>();
	func<0.f>();

	std::array<int, 3> arr;

	int a[5]{};
	func(a);

	// func({ 3,6,7 }); have no

	// func(arr); 


	std::cin.get();
	return 0;
}