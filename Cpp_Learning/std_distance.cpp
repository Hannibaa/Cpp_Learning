#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <MyLib/containers.h>

/*
             KADDA Aoues
			 1. testing type Iterator
			 2. concept on Iterator
			 3. requires expression with typename on template to template


*/

template<typename ForTypeOnly, typename Iter>
requires std::same_as<Iter,typename std::vector<ForTypeOnly>::iterator>
void print_Iter(Iter Begin, Iter End) {
	for (auto It = Begin; It != End; ++It)
		print_ << ": " << *It << end_;
}

int main()
{
	std::vector<std::string>   vStr{ "hello","world","how", "are", "you" };
	std::vector<int>           vInt{ 1,3,4,5,6,7,8,9 };

	Print_(color::Green, "Distance is : ") << end_;
	print_ << std::distance(vInt.begin(), vInt.end()) << " size is : " << vInt.size() << end_;
	print_ << "print some value :" << end_;
	print_Iter<int>(vInt.begin(), vInt.begin() + 4); newline_;
	print_Iter<std::string>(vStr.begin(), vStr.end());

	std::cin.get();
	return 0;
}