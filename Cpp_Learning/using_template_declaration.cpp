#include <iostream>
#include <vector>

using namespace std;

class Random {
public:
	template<typename T, uint32_t range>
	static T get_(T x = T{}) { return x + static_cast<T>(std::rand() % range); }

	template<typename T, uint32_t range>
	T _get(T x = T{}) { return x + static_cast<T>(std::rand() % range); }
};

template<typename T, typename U, uint32_t range>
T getnumber(T x = T{}) {
	T y = U::template get_<T, range>(x);      // as static

	U rand_;
	T z = rand_.template _get< T, range>(x); // create object;

	return z;
}

int main()
{
	int x = Random::template get_<int, 100>(200);
	cout << x << " first \n";

	for (int i = 0; i < 10; ++i)
		cout << getnumber<int, Random, 100>() << endl;




	cin.get();
	return 0;
}