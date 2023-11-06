#include <iostream>
#include <Mylib/Console_Library/escape_code.h>

/* 
    author : KADDA Aoues 
	example of bit field and template<> and structure
	we name this file version 1;
	
*/


struct Int {
	unsigned int  i : 16;

	operator int() {
		return i;
	}
};

template<size_t N>
struct INT {
	unsigned int i : N;

	INT(unsigned int _i = 0U) :i{ _i } {}

	operator int() {
		return i;
	}
};

template<size_t N>
struct cInt {
	unsigned int i : N;              // int 0 -> N - 1     if N = 7
	unsigned int ci : 32 - N;        // int N -> 31        32 - 7 = 25

	cInt(unsigned int _i = 0U) {
		*this = std::bit_cast<cInt>(_i);
	}

	operator unsigned int() const {
		return i;
	}

	unsigned int compliment() const {
		return ci;
	}

	unsigned int whole() const {
		return std::bit_cast<unsigned int>(*this);
	}

};



int main() {

	Int i{}; i.i = 0xff;  // 255

	Int i1{};  i1.i = 0xff'1f; //65311  // 65535
	Int i2{};  i2.i = 0x0f'ff'1f; // 16777215

	INT<1> i3{0x02'ff'5a};  // 196445
	0xff'5a;                // 65370

	cInt<16> i4{ 0x02'ad'fc'ee }; // 0x02ad = 685  ; 0xfcee = 64750;
	0x02ad; 0xfcee;

	print_ << "value i0 is [" << i.i <<"]\n";
	print_ << "value i1 is [" << i1.i <<"]\n";
	print_ << "value i2 is [" << i2.i <<"]\n";
	newline_;
	Print_(color::Green, "Using operator int() conversion :") << end_;
	print_ << "value i0 is [" << i <<"]\n";
	print_ << "value i1 is [" << i1 <<"]\n";
	print_ << "value i2 is [" << i2 <<"]\n";

	print_ << "value i3 is [" << i3 << "]\n";

	print_ << "size of int<1> " << sizeof(INT<1>) << end_;
	print_ << "size of int<16> " << sizeof(INT<16>) << end_;
	print_ << "size of int<31> " << sizeof(INT<31>) << end_;

	newline_;
	Print_(color::Green, "Now test cInt<>") << end_;

	print_ << "value of i4 is " << i4 << end_;
	print_ << "value the compliment is " << i4.compliment() << end_;
	print_ << "value of whole number " << i4.whole() << end_;




	std::cin.get();
	return 0;
}