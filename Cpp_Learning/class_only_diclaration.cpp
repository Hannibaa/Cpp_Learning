#include <iostream>

class first;

class second {
public:
	template<typename T>
	T declvall();
};

int main()
{
	// first yes;

	// decltype(first);
	//std::cout << " " << sizeof(first) << end_;

	second Second;
	std::cout << "sizeof : " << sizeof(Second) << " , " << sizeof(second) << '\n';
	//Second.declvall<char>();
	decltype(Second.declvall<int>());


	std::cin.get();
	return 0;
}