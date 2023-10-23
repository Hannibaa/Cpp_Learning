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


// this take array
template<template<typename,size_t> class Array,typename T, size_t N>
requires std::is_same_v<Array<T,N>,std::array<T,N>>
void func(const Array<T,N>& x) {
	std::cout << "is an Array of size : " << x.size() << end_;
	std::cout << "type is             : " << typeid(T).name() << end_;
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
	func(a);  // func<int[5]>(const int (&x)[5])

	// func({ 3,6,7 }); //have no

	 func(arr); 


	std::cin.get();
	return 0;
}