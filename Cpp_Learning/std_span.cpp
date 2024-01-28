#include <iostream>
#include "MyLib/containers.h"
#include "MyLib/container_utility.h"
#include "MyLib/Console_Library/escape_code.h"



template<typename T>
void print_vec(std::span<T> container, std::string_view comment) {
	Print_(color::Green, comment) << end_;
	Print_(color::Green, "size : ") << container.size() << end_;
	Print_(color::Grey35, "------------------------------------------") << end_;
	for (auto e : container) {
		print_ << e << " ";
	}
	print_ << end_ << end_;
}

template<typename T>
constexpr T summation_of(std::span<T> container) {
	T sum{};
	for (auto e : container) sum += e;
	return sum;
}

int main()
{
	std::vector<int> vec_int{ 2,5,6,7,8 };
	std::array<float, 5> arrFloat{ 2.3f,4.5f,6.7f,7.7f,9.1 };
	
	double pDoubles[4]{ 4.4,6.7,7.7,6.8 };
	char* pChar = new char[5] {'a', 'b', 'c', 'd', 0};

	print_vec<int>(vec_int,    "vector of integer : ");
	print_vec<float>(arrFloat, "array of float    : ");
	print_vec<double>(pDoubles, "static array of double : ");

	print_ << "summation of " << summation_of<int>(vec_int) << end_;
	print_ << "summation of " << summation_of<float>(arrFloat) << end_;
	print_ << "summation of " << summation_of<double>(pDoubles) << end_;

	std::cin.get();
	return 0;
}