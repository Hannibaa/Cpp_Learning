#include <iostream>
#include "MyLib/containers.h"
#include "MyLib/container_utility.h"
#include "MyLib/Console_Library/escape_code.h"

#define __exemple_2_ 


// second exemple 
#ifdef __exemple_2_

template<typename T>
T summation(std::span<T> vec) {
	T sum{};
	for (auto&& e : vec)
		sum += e;

	return sum;
}

int main() {

	std::vector<int>  vi{ 1,2,3,4,5 };
	std::vector<float> vf{ 2.2f, 1.1f, 3.3f };
	std::array<short, 3> vs{ 3 , 2 , 1 };
	std::array<int, 2> ai{ 4,7 };
	int64_t si64[4]{ 3,4,1,1 };

	int* pi = new int[4] {3, 3, 1, 1};

	Print_(color::Green, "First integer summation ") << summation<int>(vi) << end_;
	Print_(color::Fuchsia, "Second flaot summation ") << summation<float>(vf) << end_;
	Print_(color::Red, "Third short summation in array ") << summation<short>(vs) << end_;
	Print_(color::Grey, "Forth C array ") << summation<int64_t>(si64) << end_;
	Print_(color::Grey19, "Sixth array ") << summation<int>(ai) << end_;
	//Print_(color::Silver, "Fifth C heap array") << summation<int>(pi) << end_;  

	delete[] pi;
	return 0;
}

#endif __exemple_2_ // __exemple_2_






// first exemple
#ifdef __exemple_1_

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

#endif  // __exemple_1_