#include <iostream>
#include <vector>
#include <string>
#include "MyLib/Console_Library/escape_code.h"

using namespace std::string_literals;

template<typename T>
std::vector<T>& operator << (std::vector<T>& vec, const T& value) {

	vec.push_back(value);

	return vec;
}

std::vector<std::string> operator << (std::vector<std::string>& vec, const char* value) {

	vec.push_back(std::string(value));
	return vec;

}

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& vec) {

	os << "size[" << vec.size() << "]\n";
	for (const auto& e : vec)
		os << e << " ";

	return os;
}

template<typename T>
std::vector<T>& operator >> (std::vector<T>& vec, T& _data) {
	// check if T is POD data
	static_assert(std::is_trivially_copyable_v<T>, "T should be copyable POD type");

	// check if available data to transfer from vector to data
	if (1 > vec.size()) {
		Print_(color::Red, "No data available to transfer, check size of vector") << end_;
		return vec;
	}

	// cach  the location towards the end of the vector where the pulled data starts
	size_t i = vec.size() - 1ull;

	// Physically copy the data from vector to veriable;
	std::memcpy(&_data, vec.data() + i, sizeof(T));

	// Shrink the vector to remove read bytes, and reset end position
	vec.resize(i);

	// return the target vector so it can -- Chained --
	return vec;
}

template<typename T, typename U>
std::vector<T>& operator >> (std::vector<T>& vec, U& _data) {
	// check if T is POD data
	static_assert(std::is_trivially_copyable_v<T>, "T should be copyable POD type");
	static_assert(std::is_trivially_copyable_v<U>, "U should be copyable POD type");

	// cach location in vec.data() memory todo
	size_t i = (vec.size() * sizeof(T) - sizeof(U)) / sizeof(T);

	// check if U data physical size is adequat with vector size
	if (i == 0) {
		Print_(color::Red, "size data and vector size") << end_;
		_data = U{};
		return vec;
	}

	// copy physical last data from vector to U type;
	std::memcpy(&_data, vec.data() + i, sizeof(U));

	return vec;
}


int main()
{
	std::vector<int> vi;
	std::vector<std::string> vstr;

	vi << 23 << 34 << 56;

	print_ << vi << end_;

	//vstr << "hello"s << "world";

	//print_ << vstr << end_;

	float f{};

	vi >> f;

	print_ << "float : " << f;

	//vi >> f;



	//int x{}, y{}, z{}, w{};

	//vi >> x >> y >> z >> w;

	//print_ << vi << end_;
	//print_ << x << " " << y << " " << z << " " << w << end_;



	std::cin.get();
	return 0;
}