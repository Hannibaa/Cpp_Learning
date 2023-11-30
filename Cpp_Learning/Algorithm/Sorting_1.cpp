#include <iostream>
#include <algorithm>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/container_utility.h"
#include "MyLib/random_vector.h"


int main()
{
	auto v = vu::makeRandomContainer<std::vector>(0.f, 120.f, 10);

	cu::print_container(v, "vector v :");

	size_t k = 2;

	std::sort(v.begin(), v.end());

	cu::print_container(v, "vector v after sort :");

	std::cin.get();
	return 0;
}