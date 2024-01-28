#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/CFile.h"
#include "MyLib/stringfunctionhelper.h"
#include "MyLib/random_generator.h"
#include "MyLib/chrono/Timer.h"

template<typename T>
T get_random_element(const std::vector<T>& vec) {
	return vec[rng::Random::rand() % vec.size()];
}

int main()
{
	Timer timer;
	fs::path filename = R"(C:\Users\Acer\source\Course C++\Cpp_Learning\Cpp_Learning\matrix.txt)";

	auto str = File::loadFileToString(filename);

	auto vec = Str::to_vector_memcpy(str);

	print_ << "size of vector : " << vec.size() << end_;
	for(int i = 0 ; i != 10 ; ++i)
	print_ << "get random element " << get_random_element(vec) << end_;
	print_ << "time for this function : " << timer.GetElapsedTime() << end_;
	std::cin.get();
	return 0;
}