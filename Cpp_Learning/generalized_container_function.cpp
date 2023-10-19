#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <span>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/random_vector.h"
#include "MyLib/vector_utility1.h"
/*
	 HERE WE NEED TO EXPLAIN HOW TO WRITE OUT DATA IN THIS
	 1. STUDYING OF FUNCTIONAL PROGRAMMING AS MATHEMATICAL FUNCTION
	 2. OOP IN THIS SITE WE SHOULD GO BJARN STROUSTUP.
*/

using namespace std;
template<typename iter>
constexpr auto sum_(iter it_begin, iter it_end) {

	typename iter::value_type sum{};

	for (auto it = it_begin; it != it_end; ++it) {
		sum += *it;
	}

	return sum;
}

template<typename T>
constexpr auto sum_(T* _array_begin, T* _array_end) {

	T sum{};

	for (auto it = _array_begin; it != _array_end; ++it)
		sum += *it;

	return sum;
}


int main()
{

	auto vec1 = vu::makeRandomContainer<vector>(0, 100, 10);

	auto array1 = vu::makeRandomArray<int, 10>(0, 100);

	auto list1 = vu::makeRandomContainer<std::list>(0, 100, 3);

	auto list2 = vu::makeRandomContainer<std::forward_list>(0, 100, 4);

	auto array_heap = vu::makeRandomCarray(0, 100, 5);

	int array_stack[10]{};
	vu::makeRandomStackArray<10>(array_stack, 0, 100);

	print_ << "vector : " << end_;
	vu::print_container(vec1, 40);
	print_ << " Size[" << vec1.size() << "]\n";
	newline_;

	print_ << "array : " << end_;
	vu::print_container(array1, 40);
	print_ << " Size[" << array1.size() << "]\n";
	newline_;

	print_ << "list : " << end_;
	vu::print_container(list1, 40);
	print_ << " Size[" << list1.size() << "]\n";
	newline_;

	print_ << "forward_list : " << end_;
	vu::print_container(list2, 40);
	print_ << " Size[" << list2.max_size() << "]\n";
	newline_;

	print_ << "array in heap : " << end_;
	vu::print_container(array_heap, 5, 35);
	print_ << " Size[" << 5 << "]\n";
	newline_;

	print_ << "array in stack : " << end_;
	vu::print_container(array_stack, 10, 34);
	print_ << " Size[" << 10 << "]\n";
	newline_;

	Print_(color::Green, "summation of vector is ") << sum_(vec1.begin(), vec1.end()) << end_;
	Print_(color::Green, "summation of array is  ") << sum_(array1.begin(), array1.end()) << end_;
	Print_(color::Green, "summation of list is   ") << sum_(list1.begin(), list1.end()) << end_;
	Print_(color::Red, "summation of array in stack ") << sum_(array_stack, array_stack + 10) << end_;
	Print_(color::Fuchsia, "summation of array in heap ") << sum_(array_heap, array_heap + 5) << end_;

	cin.get();
	return 0;
}