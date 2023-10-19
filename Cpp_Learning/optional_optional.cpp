#include <iostream>
#include <optional>
#include <random>
#include <string>

#define end_   '\n'
#define line_   std::cout << "---------------------------------------------------------------------\n"
#define wait_  std::cin.get()
#define print  std::cout 

using namespace std;

int random(int range = 100) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> intdis(0, range);

	return intdis(gen);
}


optional<string> getString(uint32_t number) {

	if (number > 100) return {};

	if (random() > number) return "is superior of";
	else return {};
}



int main()
{
	for (int i = 0; i < 20; i++) {
		auto str = getString(50);
		print << str.has_value() << end_;
		if(str)
		print << str.value() << end_;
		line_;
	}

	cin.get();
	return 0;
}