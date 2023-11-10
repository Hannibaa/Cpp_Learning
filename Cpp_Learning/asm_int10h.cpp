#include <iostream>

/*   
              check interruption int 10h ; but isn't working
*/

void test() {
	_asm {
		mov ah, 0
		mov al, 13h
		int 10h
	};
}

int main() {

	test();


	std::cin.get();
	return 0;
}