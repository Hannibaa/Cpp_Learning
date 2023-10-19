#include <iostream>
#include <vector>
#include <numeric>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"


using namespace std;


int main()
{
	print_ << GREEN_FG << "     test of std::iota() function     " << RESETMODE << end_;

	std::vector<int> v{ 1,2,3,7 };

	std::iota(v.begin(), v.end(), 100);

	print_ << BLUE_FG << "The value of v is " << RESETMODE;
	for (auto& e : v) print_ << setw(3) << e << ' ';



	cin.get();
	return 0;
}