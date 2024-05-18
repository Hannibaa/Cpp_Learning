#include <iostream>
#include <Windows.h>
#include <MyLib/Console_Library/escape_code.h>




int main() {
	DWORD d = 0;

	// SHOULD SET CONSOLE MODE TO THAT MYSTERY MODE FEATURE 0X0004.
	GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &d);
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), d | 0x0004) ;// Mystery Console Mode Feature
	//GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &d);
	//SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), d | 0x0002);

	Print_(color::Green, "======== Big Title ==========") << end_;
	//print_color(color::Green, "======== Big Title ============");

	Printm_(10, 10, color::Red, "Hello escape code") << end_;

	wait_;
	return 0;
}