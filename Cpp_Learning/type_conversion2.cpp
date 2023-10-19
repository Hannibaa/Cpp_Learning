#include <iostream>
#include <thread>
#include <type_traits>
#include "MyLib/Console_Library/escape_code.h"
#include "NsValue.h"


using namespace std;

// we making a type that have conversion function return roundemly any value randomly
// we can generalize in header file by NsValue 
// we can combaine here with random and conversion function operator.


int main()
{
	NsValue  t1{ 100.f,300.f };

	NsValue t3(100, 200, 400);

	NsValue t2{ {100,58,89,400} };

	int count_1{}, count_2{};

	Print_(color::Green, "first one is ") << end_;
	print_value(t1);
	newline_;

	Print_(color::Green, "second one is ") << end_;
	print_value(t2);
	newline_;

	Print_(color::Green, "third one is ") << end_;
	print_value(t3);
	newline_;

	for (int i = 0; i < 16; ++i) {
	      print_ << CELL(5, left, t1) << CELL(5, right, t2) << CELL(10, right, t3) << end_;
		  std::this_thread::sleep_for(159ms);
	}
	
	
	cin.get();
	return 0;
}