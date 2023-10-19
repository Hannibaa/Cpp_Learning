#include <iostream>

#define end_    '\n'
#define line_   std::cout << "---------------------------------------------------------------------\n"
#define wait_   std::cin.get()
#define print_  std::cout 

using namespace std;
template<typename T>
class Point {
	T x;
	T y;
public:
	Point() = default;
	Point(T _x,T _y):x{_x},y{_y}{}

	void printPoint() const {
		std::cout << x << "  " << y << "\n";
	}
 };

int main()
{
	Point<float> p1{ 2.f,5.6f };
	Point<std::string> pstr{ "this","that" };

	p1.printPoint();
	pstr.printPoint();


	cin.get();
	return 0;
}