#include <iostream>
#include <vector>
#include <algorithm>
#include "MyLib/Console_Library/escape_code.h"

void check_equidistance(std::vector<int>& vec, int min) {
	for (int i = 0; i < vec.size() - 1; ++i) {
		if (vec[i + 1] - vec[i] < min) {
			vec[i + 1] = vec[i] + min;
		}
	}
}

void prnt_vec(const std::vector<int>& vec) {
	print_ << "---------------------------------------------------------\n";
	for (const auto& e : vec) print_ << e << " , ";
	print_ << end_;
	print_ << "---------------------------------------------------------\n";
}


int main() {

	std::vector<int>    v{ 0,1,3,10,11,7 };
	prnt_vec(v);
	std::sort(v.begin(), v.end());
	print_ << "after sorting\n";
	prnt_vec(v);
	print_ << "check equidistance " << end_;
	check_equidistance(v, 2);
	prnt_vec(v);


	wait_;
	return 0;
}