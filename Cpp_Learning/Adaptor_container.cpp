#include <iostream>
#include <MyLib/containers.h>
#include "MyLib/Console_Library/escape_code.h"

template<typename T>
std::vector<T> operator^(const std::vector<T>& v1, const std::vector<T>& v2) {

	static_assert(std::is_arithmetic_v<T>, "T type should be arithmetic");

	if (v1.size() != v2.size()) {
		std::cout << COLOR(color::Red, "Not equal size to do operation") << end_;
		return {};
	}

	std::vector<T> result;

	for (int i = 0; i < v1.size(); ++i ) {
		result.push_back(v1[i]*v2[i]);
	}

	return result;
}

template<typename T>
T operator*(const std::vector<T>& v1, const std::vector<T>& v2) {

	static_assert(std::is_arithmetic_v<T>, "Type should be arithmetic");

	if (v1.size() != v2.size()) {
		std::cout << COLOR(color::Red, "Not equal size to do operation") << end_;
		return {};
	}

	T result{};

	for (int i = 0; i < v1.size(); ++i) {
		result += v1[i] * v2[i];
	}

	return result;
}

template<typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2) {

	static_assert(std::is_arithmetic_v<T>, "Type should be arithmetic");

	if (v1.size() != v2.size()) {
		std::cout << COLOR(color::Red, "Not equal size to do operation") << end_;
		return {};
	}

	std::vector<T> result;

	for (int i = 0; i < v1.size(); ++i) {
		result.push_back( v1[i] + v2[i] );
	}

	return result;
}



template<typename Container>
class Adapter {
public :
	Adapter(const Container& container) : _container{container}{}

private:
	std::vector<T> _container;
};


int main()
{
	std::vector v1{ 1,2,3,4,5 };
	std::vector v2{ 3,3,3,4,4 };

	auto v = v1 ^ v2;
	auto v_pulus = v1 + v2;

	vu::print_container(v);
	newline_;
	print_ << "valeur of scalar product v1 * v2 : " << v1 * v2 << end_;

	wait_;
	return 0;
}