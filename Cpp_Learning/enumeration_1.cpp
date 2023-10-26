#include <iostream>



constexpr int get(int x = 1) {
	return x;
}

//template<size_t N>  not work
//enum ayam {
//	mon = N , 
//};

template<int initial> 
struct dayss {
	static enum {mon = initial, tus, wed, thr };
};


int main() {

	constexpr int i = 1;

	int j{ 0 };

	enum Ayam 
	{
		sabte = get(), ahad, ithnayn, thulathaa, arbiaa, khamis, jomoa
	};

	enum Day {  // constexpr int 
		sat = i, sun , mon , tus , wed , thr , fri 
	};

	auto today = dayss<3>::mon;

	std::cout << " value of mon 0 and 4 : " << dayss<0>::mon << " " << dayss<4>::mon << '\n';
	std::cout << " value of tus wed     : " << dayss<0>::tus << " " << dayss<4>::wed << '\n';

	std::cin.get();
	return 0;
}