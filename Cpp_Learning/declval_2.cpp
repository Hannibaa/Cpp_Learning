#include <iostream>
#include <utility>



int main() {
	int k = 34500;
	decltype(std::declval<int>()) i = 3000;
	decltype(std::declval<int&>()) ii = k;

	decltype(std::declval<const int&>()) j = 445;

	std::cout << "accepted";


	std::cin.get();
	return 0;
}