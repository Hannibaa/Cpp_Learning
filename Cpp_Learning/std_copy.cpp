#include <iostream>
#include <algorithm>
#include <vector>
#include "MyLib/Console_Library/escape_code.h"
#include <MyLib/vector_utility1.h>

/* 
    this exemple comparing two methode of erasing element from vector.
*/

template<typename T>
std::vector<T> erase_from_to(const std::vector<T>& vec, size_t pos, size_t size) {

	if (size > vec.size()) {
		Print_(color::Red, "Overflow, check sizing size") << end_;
		return {};
	}

	std::vector<T> v(vec.size() - size);

	std::copy(vec.begin(), vec.begin() + pos, v.begin());
	std::copy(vec.begin() + pos + size, vec.end(), v.begin() + pos);
	
	return v;
}


int main()
{
	std::vector<int>  v{ 0,1,2,3,4,5,6,7,8,9 };
	auto w = v;

	print_ << "size of v : " << v.size() << end_;
	vu::print_container(v, "vector v : ");
	newline_;

	int pos = 4; 
	int size = 5; // exclude.

	v = vu::erase_from_to(v, pos, size);

	w.erase(w.begin() + pos, w.begin() + pos + size);

	char text[100]{};

	sprintf_s(text, "v after erasing %d element from position %d :", size, pos);


	vu::print_container(v, text);
	text[0] = 'w'; newline_;
	vu::print_container(w, text);

	std::cin.get();
	return 0;
}