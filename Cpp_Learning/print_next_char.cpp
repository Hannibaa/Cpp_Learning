#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"

#define end_    '\n'
#define line_   std::cout << "---------------------------------------------------------------------\n"
#define wait_   std::cin.get()
#define print_  std::cout 

using namespace std;

struct _char {
	char c[1]{};
};

void printNextChar(const _char& _vchar, int n_char, int n_char_line) {
	for (int i = 0; i < n_char; ++i) {
		print_ << "char [" << i << "]" << +_vchar.c[i] << "  ";
		if (i % n_char_line == n_char_line - 1) print_ << end_;
	}
}

int main() {

	_char k;

	k.c[0] = 'A';

	print_ << "k is " << &k.c << end_;
	print_ << "k.c[0] " << k.c[0] << end_;

	printNextChar(k, 1000, 30);


	wait_;
	return 0;
}
