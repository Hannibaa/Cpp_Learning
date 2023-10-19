#include <iostream>
#include <conio.h>

#define end_    '\n'
#define line_   std::cout << "---------------------------------------------------------------------\n"
#define wait_   std::cin.get()
#define print_  std::cout 

using namespace std;


int main()
{

	while (true) {

		int i = _kbhit();
		if (!_kbhit()) print_ << "key is pressed " << i << "\n";

		char c = _getch();

		if (c == 'e') {
			print_ << "break \n"; break;
		}

		putchar(c);
	}


	cin.get();
	return 0;
}