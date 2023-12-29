#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/CFile.h"

// function that take string<Char> and converted to vector<Char> :
// using std::copy function
template<typename TChar>
std::vector<TChar>  to_vector(const std::basic_string<TChar>& String) {

	std::vector<TChar> vec(String.size());
	std::copy(String.begin(), String.end(), vec.begin());
	return vec;
}

// function that take string<Char> and converted to vector<Char> :
// using memcpy function
template<typename TChar>
std::vector<TChar>  to_vector_memcpy(const std::basic_string<TChar>& String) {

	std::vector<TChar> vec(String.size());
	std::memcpy(vec.data(), String.data(), String.size() * sizeof(TChar));
	return vec;
}


int main()
{
	fs::path filename = R"(C:\Users\Acer\source\Course C++\Cpp_Learning\Cpp_Learning\matrix.txt)";

	auto str = File::loadFileToString(filename);

	print_ << "size of string : " << str.size() << end_;
	print_ << "first 10 char : " << str.substr(0, 10) << end_;

	// convert string to vector

	auto tp = std::chrono::steady_clock::now();
	auto vec = to_vector_memcpy(str);
	std::chrono::duration<float>  duration = std::chrono::steady_clock::now() - tp;
	print_ << "time to load file with memcpy()  : " << duration << end_;

	tp = std::chrono::steady_clock::now();
	auto vec1 = to_vector(str);
	duration = std::chrono::steady_clock::now() - tp;
	print_ << "time to load file with copy(): " << duration << end_;

	print_ << "size of vector : " << vec.size() << end_;
	print_ << "first element : " << vec[0] << end_;

	std::cin.get();
	return 0;
}