#include "exemple_h.hpp"




namespace functions {

	template<typename T>
	constexpr T cubic(T x) {
		return x * x * x;
	}

	template<typename T>
	constexpr T square(T x) {
		return x * x;
	}

	template<typename T>
	void print(T x) {
		std::cout << x << end_;
	}

	
	float add(float x, float y) {
		return x + y;
	}

}