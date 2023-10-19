#include <iostream>
#include <MyLib/containers.h>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"


// sum version 1
template<template<typename...> class Container,typename T>
typename Container<T>::value_type sum_of_ver1(const Container<T>& C) {
	typename Container<T>::value_type sum{};
	for (auto& e : C) sum += e;

	return sum;
}

template<typename T0, template<typename,T0 > class Array, typename T, T0 N>
typename Array<T, N>::value_type sum_of_ver1(const Array<T, N>& arr) {
	typename Array<T, N>::value_type sum{};
	for (auto e : arr) sum += e;

	return sum;
}

template<typename T>
T sum_of_ver1(T* vec, size_t N) {

	T sum{};
	for (size_t i = 0; i != N; ++i) sum += *(vec + i);

	return sum;
}



// using iterator   sum version 2
template<typename Container>
typename Container::value_type sum_of_ver2(const Container& container) {

	typename Container::value_type sum{};

	for (auto it = container.begin(); it != container.end(); ++it) sum += *it;

	return sum;
}

template<typename T>
T sum_of_ver2(T* ver, size_t N) {
	T sum{};
	for (size_t i = 0; i != N; ++i) sum += *(ver + i);

	return sum;
}

// using std::span  sum version 3
template<typename T>
T sum_of_ver3(const std::span<T>& vec) {

	T  sum{};
	for (auto& e : vec) sum += e;

	return sum;
}

// version 4 operator[]
template<typename Container>
typename Container::mapped_type sum_of_ver4(const Container& container) {
	typename Container::mapped_type sum{};

	for (auto& e : container) sum += e.second;

	return sum;
}

// We add to container this vector object.
template<typename T>
using MapVector = std::map<size_t, T>;


int main()
{
	std::vector<int> vec{ 1,3,4,5,6,5,43,5 };
	std::array<float, 4> arr{ 3.4,5.3,5.5,1.4 };
	
	int char_arr[5]{ 20,50,77,90,100 };

	std::list list_{ 3,3,4,5,6,1 };
	std::set Set{ 3,55,6,7,8,8,8 };
	MapVector<float> Map;

	Map[0] = 1.5; Map[1] = 2.1; Map[2] = 1.5; 
	Map[1] = 3.2;

	// version 1
	print_ << "sum of vec :" << sum_of_ver1(vec) << end_;
	print_ << "sum of arr :" << sum_of_ver1(arr) << end_;
	print_ << "sum of arr :" << sum_of_ver1(list_) << end_;
	print_ << "sum of arr :" << sum_of_ver1(char_arr,5) << end_;
	print_ << "size of set " << Set.size() << " value sum : " << sum_of_ver1(Set) << end_;
	//print_ << "size of map " << Map.size() << " value sum : " << sum_of_ver1(Map) << end_;// not applicable
	print_ << "size of map " << Map.size() << " value sum : " << sum_of_ver4(Map) << end_;
	newline_;
	// version 2
	print_ << "sum of vec :" << sum_of_ver2(vec) << end_;
	print_ << "sum of arr :" << sum_of_ver2(arr) << end_;
	print_ << "sum of arr :" << sum_of_ver2(list_) << end_;
	print_ << "sum of arr :" << sum_of_ver2(char_arr,5) << end_;
	print_ << "sum of set :" << sum_of_ver2(Set) << end_;
	newline_;
	// version 3
	print_ << "sum of vec :" << sum_of_ver3<int>(vec) << end_;
	print_ << "sum of arr :" << sum_of_ver3<float>(arr) << end_;
	//print_ << "sum of arr :" << sum_of_ver3<int>(list_) << end_;// not work for list not contigueces memory
	// for Set is not posible .
	print_ << "sum of arr :" << sum_of_ver3<int>(char_arr) << end_;


	wait_;
	return 0;
}