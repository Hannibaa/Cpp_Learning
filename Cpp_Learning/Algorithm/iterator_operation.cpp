#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/containers.h"

int main()
{
	std::vector<float>   vf{ 1.11f,2.5f,3.44f };



	for (const auto& e : vf) print_ << e << " ";
	newline_;

	print_ << "diff " << vf.end() - vf.begin() << end_;

	print_ << "addition " << *(vf.end() - 1) << end_;

	print_ << "decrement end " << *(--vf.end()) << end_;

	print_ << "increment begin " << *(++vf.begin()) << end_;




	std::cin.get();
	return 0;
}