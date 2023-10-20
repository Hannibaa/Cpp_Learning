#include <iostream>
#include <MyLib/Console_Library/escape_code.h>
#include <MyLib/containers.h>
#include <MyLib/vector_utility1.h>
#include <MyLib/random_vector.h>


template<typename Container, typename T, typename Generator>
Container make_container(const T& t_begin, const T& t_end, size_t Size, Generator generator) {

	Container container{};

	for (size_t i = 0; i < Size; ++i) {
		container.push_back(generator(t_begin,t_end, i));
	}

	return container;
}



int main() {

	auto vec = make_container<std::vector<int>>(10, 209 ,10, [](int x, int y, size_t k)->int
		{ return  rand(); });

	vu::print_container(vec);

	wait_;
	return 0;
}