#include <iostream>
#include <MyLib/random_generator.h>

#define end_ '\n'
/* 
*          Kadda Aoues 
           decltype() : 
*/

template<typename T>
T make_type();

template<typename T>
T get_value() {
	RNG::iRG<T> i;

	return i(0, 10);
}



int main()
{
	int i = 1i32;

	int* pi = &i;

	int& refi = i;

	int&& lval = 44;

	const char const_c = 'a';

	const char& cref_c = 'k';

	const char* const* const_ptr ;


	decltype(230) i1{};  // int
	decltype(i) i2{};    // int
	decltype(pi) pi1 = &i; // int*

	decltype(refi) refi1 = i;  // int&;

	decltype(lval) lval1 = 23 + i; // int&&

	decltype(const_c) const_c1 = const_c;        // const char
	decltype(cref_c)  cref_c1 = cref_c;         // const char&
	//decltype(const_ptr) const_ptr1 = const_ptr;  // const char* const * 

	std::cout << "print value : " << get_value<int>() << end_;

	decltype(get_value<int>()) v2 = 7000;
	decltype(get_value<int&>()) v3 = v2;

	char z{ 3 };

	decltype(make_type<char&>() = make_type<const char&>()) ss = z ;


	//std::cin.get();

	return 0;
}