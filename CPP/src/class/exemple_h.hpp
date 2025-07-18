#pragma once
#include <iostream>

#define end_ '\n'

namespace functions {

	template<typename T>
	constexpr T cubic(T x);

	template<typename T>
	constexpr T square(T x);

	template<typename T>
	void print(T x);

	float add(float, float);
}