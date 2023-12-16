#include <iostream>
#include <thread>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/random_generator.h"

#define _BIT(i, N)    ((uint64_t(N) >> ((uint64_t)i)) & 1ul)

void print_unicode_chart(wchar_t from = L'\x2500' , wchar_t to = L'\x25FF', int by_line = 10) {
	int k{};
	for (wchar_t c = from ; c != to ; ++c) {
		wprint_ << std::hex << wCOLOR(color::Red, (int)c) << L'|';
		wprint_ << wCOLOR(color::Green, c) << L"  ";

		if (++k % by_line == 0) { wnewline_; }
	}

}

// this is 4X4 shape image character
void draw_shape(int x, int y, wchar_t c, int pos, wchar_t anti_c, int length = 4, int width = 4) {
	wchar_t w{};
	int area = length * width;
	for (int j = 0; j != area; ++j) {
		int _x = x + j % length;
		int _y = y + (j - j%length)/length;

		w = _BIT(area - j - 1, pos) ? c : anti_c;

		wprintm_(_x, _y) << w;
	}
}

void draw_shape() {
	// todo using double loop on x and on y;
}

int main()
{

	INIT_UNICODE_TEXT;

	WPrint_(color::Green, L"Braille Character") << wend_;

	int L = 0b0100'0100'0110'0000;
	//int L1 = ;
	int _4 = 0b0100'0110'0010'0000;
	int _41 = 0b0011'0110'0000'0000;

	int plan = 0xff'ff'ff'ff;

	draw_shape(2, 2, L'\x25aa', plan, 0, 8,8 );

	for (int d = 0; d < 100; ++d) {
		draw_shape(20, 20, L'\x25aa', RNG::Random::rand(), 0, 5, 5);
		draw_shape(14, 20, L'\x25aa', RNG::Random::rand(), 0, 5, 5);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		//wwait_;
		esc::wcls();
		//esc::wclear_line(1, 1);
	}

	// print_unicode_chart();

	std::wcin.get();
	return 0;
}





	//int n = 0b1010;
	//wprint_ << _BIT(0, n) << wend_;
	//wprint_ << _BIT(1, n) << wend_;
	//wprint_ << _BIT(2, n) << wend_;
	//wprint_ << _BIT(3, n) << wend_;
	//wprint_ << _BIT(4, n) << wend_;
	//wprint_ << _BIT(5, n) << wend_;