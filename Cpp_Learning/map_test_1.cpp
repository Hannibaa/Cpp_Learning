#include <iostream>
#include <MyLib/containers.h>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <MyLib/stringfunctionhelper.h>
#include "random_container.h"



int main()
{
	std::map<std::string, float> Map1;
	std::map<size_t, std::string> map_str;
	std::map<size_t, double>  map_value;
	std::unordered_map<float, std::string> str_float;
	std::set<float>  set_float;
	std::unordered_set<long long int> un_set_ll;

	RNG::fRG<float> float_gen;
	RNG::fRG<double> double_gen;
	RNG::iRG<size_t> int_gen;


	make_random_map1(Map1, []() {return Str::getRandomString("@@//@@//20@@"); }, [&]() {return float_gen(0.f, 100.f); }, 5);

	Print_(color::Red, "Size of map is : ") << Map1.size() << end_;
	vu::print_map("Print value of   map<string,float>   ", Map1);

	newline_;
	make_random_map1(map_str, Inc_Int<0>(), []() {return Str::getRandomString2(10); }, 7);
	Print_(color::Red, "Size of map is : ") << map_str.size() << end_;
	vu::print_map("Print value of map<size_t, string>  ", map_str);
	newline_;
	
	make_random_map1(map_value,Inc_Int<1>(), [&]() {return double_gen(0.0, 1.0); }, 3);
	Print_(color::Red, "Size of map is : ") << map_value.size() << end_;
	vu::print_map("Print value of map<size_t,double>  ", map_value);

	make_random_map1(str_float, [&]() {return double_gen(0.0, 1.0); }, []() {return Str::getRandomString2(10); }, 5);
	Print_(color::Red, "Size of map is : ") << str_float.size() << end_;
	vu::print_map("Print value of map<size_t,double>  ", str_float);

	make_random_set1(set_float, [&](){return float_gen(10.5f, 20.f); }, 10);
	Print_(color::Red, "Size of set : ") << set_float.size() << end_;
	vu::print_container(set_float);
	newline_;

	make_random_set1(un_set_ll, Inc_Int<43>{}, 10);
	Print_(color::Red, "Size of set : ") << un_set_ll.size() << end_;
	vu::print_container(un_set_ll);

	newline_; wait_; set_float.clear();
	print_ << "clear set_float for new data :" << end_;
	make_random_set1(set_float, [&]() {return float_gen(0.0, 0.1); }, 6);
	Print_(color::Olive, "using more generic function size of set ") << set_float.size() << end_;
	vu::print_container(set_float);
	std::cin.get();
	return 0;
}