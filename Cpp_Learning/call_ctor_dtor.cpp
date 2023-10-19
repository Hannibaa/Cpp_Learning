#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "life_time.h"


using namespace std;


int main()
{
	// call this function at exit
	std::atexit(Lifetime::print_result_dtor);

	Lifetime obj1;
	Lifetime obj2(23.44);

	Lifetime* ptr;
	ptr = new Lifetime(3.66);
	delete ptr;
	ptr = new Lifetime();

	
	Lifetime::print_result();
	delete ptr;
	cin.get();
	return 0;
}