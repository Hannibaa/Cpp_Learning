#include <iostream>

#define end_ '\n'

/*
                     KADDA Aoues 
					 define sizeof void as null 0
					 10 / 30 / 2023

*/

/// 1. using struct 

template<typename T>
struct Sizeof {
	constexpr static size_t Size = sizeof(T);
};

template<>
struct Sizeof<void> {
	constexpr static size_t Size = 0;
};

/// 2. using variable template

template<typename T>
const size_t _sizeof = sizeof(T);

template<>
const size_t _sizeof<void> = 0i64;

int main()
{
	// here size of void is undefined so we want to define size of void as 0 null.
	// std::cout << "size of void " << sizeof(void) << end_; // not defined or not allowed

	Sizeof<int>::Size;
	Sizeof<void>::Size;

	_sizeof<int> ;
	_sizeof<double>;
	_sizeof<void>;
	_sizeof<int>;

	std::cout << _sizeof<int> << end_;

	std::cin.get();
	return 0;
}