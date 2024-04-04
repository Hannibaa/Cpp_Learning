#include <iostream>
#include <vector>

inline namespace Vec {

	template<typename T>
	std::vector<T> operator + (const std::vector<T>& v1, const std::vector<T>& v2) {
		std::vector<T>  v(v1.size() + v2.size());

		std::copy(v1.begin(), v1.end(), v.begin());
		std::copy(v2.begin(), v2.end(), v.begin() + v1.size());

		return v;
	}
}

int main() {

	std::vector<std::string>   v1{ "hel" , "hi" , "this"};
	std::vector<std::string>   v2{ "hello", "and"};

	auto v = v1 + v2;
	std::cout << "size of v1 " << v1.size() << "\n";
	std::cout << "size of v2 " << v2.size() << "\n";
	std::cout << "size of v " << v.size() << "\n";
	for (const auto& e : v) std::cout << e << " , ";



	std::cin.get();
	return 0;
}