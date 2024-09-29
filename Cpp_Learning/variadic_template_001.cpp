#include <iostream>

template<char ...C>
struct A {

	A() {
		str = string();
	}

	void print() {
		((std::cout << C << " "), ...);
		std::cout << '\n';
	}

	std::string string() {
		std::string str;
		((str.push_back(C)), ...);

		return str;
	}

private:
	std::string str;
};

template<int...I>
struct Sum {
	Sum() {
		int sum{};
		((sum += I), ...);

		S = sum;
	}

	int S;
};

// this not working , because not allow parameter pack at the end of list
//template<int...I, char ... C>
//struct E {
//
//};

int main() {

	A<'a'>   a;
	A<'k', 'd'>  kd;
	A<'a', 'b', 'd', 'a', 'a'>  aa;

	Sum<23, 4, 6> ss;

	std::cout << a.string() << " " << aa.string() << '\n';
	std::cout << "summation : " << ss.S << '\n';

	
	return 0;
}