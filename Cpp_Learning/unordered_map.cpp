#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "MyLib/Console_Library/escape_code.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    structure for image text 
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

struct AsciiImage {
	std::string          text;
	int                   dx;
	int                   dy;
};

void print_ascii_image(const AsciiImage& img) {
	print_ << "S[" << img.text << "][" << img.dx << "," << img.dy << "]\n";
}

using VecImage = std::vector<AsciiImage>;
using MapPack  = std::unordered_map<std::string, VecImage>;

void print_vec_img(const VecImage& vec) {
	for (const auto& e : vec) print_ascii_image(e);
}

void print_map(const std::string name, MapPack& map) {
	print_ << "===================================================\n";
	print_ << "name : " << name << end_;
	print_ << "size : " << map[name].size() << end_;
	print_vec_img(map[name]);
	print_ << "===================================================\n";
}

int main() {

	VecImage   vec;
	
	MapPack   map;

	vec.emplace_back("hello", 10, 10);
	vec.emplace_back("world", 4, 6);

	map["first"] = vec;

	vec.emplace_back("another", 3, 3);

	map["second"] = vec;


	print_map("first", map);
	print_ << "------------------------------------------------" << end_;
	print_map("second", map);
	print_ << "size of map " << map.size() << end_;
	print_map("third", map);

	print_ << "size of map " << map.size() << end_;

	wait_;
	return 0;
}





