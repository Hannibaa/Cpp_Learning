#include <iostream>
#include <thread>
#include <conio.h>
#include <windows.h>
#include <include/console/escape_code.h>

bool bStop = false;

void Get_Char_(char c) {
	while (true) {
		if (bStop) break;
		char ch = _getch();
		if (ch == c) {
			print_ << ch;
		}
	}
}


int main() {

	set_escape_mode;
	Print_(color::Green, "Begin") << end_;

	std::thread thr1(Get_Char_, 'a');
	std::thread thr2(Get_Char_, 'b');

	std::thread([] {
		while (true) {
			char ch = _getch();
			if (ch == ESCAPE) {
				bStop = true;
				break;
			}
		}
		}).detach();

	while (!bStop) {
		;
	}

	thr1.detach();
	thr2.detach();
	return 0;
}