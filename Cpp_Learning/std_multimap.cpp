#include <iostream>
#include <map>
#include "MyLib/Console_Library/escape_code.h"
#include <MyLib/vector_utility1.h>

#define _STRING(str)    std::string str{#str}


int main()
{
	std::multimap<std::string, std::string> mmap_str;
	
	_STRING(hello);
	_STRING(world);

	mmap_str.insert(std::make_pair("hello", "world"));
	mmap_str.insert(std::make_pair("hello", "world"));
	mmap_str.insert(std::make_pair("hello", "monde"));

	for (int i = 0; i < 5; ++i) {
		//mmap_str.insert(hello + std::to_string(i), world + std::to_string(i)); // dont do that
		mmap_str.insert(std::make_pair(hello + std::to_string(i), world + std::to_string(i)));
	}

	print_ << "size of map is " << mmap_str.size() << end_;
	vu::print_map("map of string string : ", mmap_str);

	std::cin.get();
	return 0;
} 