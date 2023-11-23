#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/containers.h"

template<typename Container>
concept has_key_and_mapped = requires{
	typename Container::key_type;
	typename Container::mapped_type;
};

template<typename Container, typename _Function>
constexpr Container::value_type apply_function(const Container& container, _Function function)
{
	typename Container::value_type _value{};

	if constexpr (has_key_and_mapped<Container>) {
		std::pair<typename Container::key_type, typename Container::mapped_type> v{};
		for (const auto& element : container) {
			v.first = function(element.first, element.second).first;
			v.second = function(element.first, element.second).second;
		}
		
		return v;
	}
	else {
        for (const auto& element : container)
		_value += function(element);
	}

	

	return _value;
}

template<typename Container>
void print_container(const Container& container, std::string_view comment = "") {
	print_ << comment << end_;
	for (const auto& element : container)
		print_ << element << " , ";
	print_ << BACKSPACE << ' ' << end_;
}

template<typename AContainer>
	requires requires {
	typename AContainer::mapped_type;
	typename AContainer::key_type;
}
void print_container(const AContainer& container, std::string_view comment = "") {
	print_ << comment << end_;
	for (const auto& element : container)
		print_ << "{" << element.first << " , " << element.second << "} ,";
	print_ << BACKSPACE << ' ' << end_;

}

int main()
{
	std::vector<int> vi{ 2,3,4,5,7 };
	std::vector<std::string> vs{ "hello","this", "world", "that", "he", "you" };

	std::map<int, float> _m{ {100,3.4f} ,{200,3.444f} ,{500,309.4f} ,{14400,13.114f} };

	print_container(vi);
	print_container(vs);
	print_container(_m);

	print_ << "the sume of double is " << apply_function(vi, [](int x) {return 2 * x; }) << end_;
	newline_;
	//print_ << "the sume of double is " << apply_function(vs, [](int x) {return 2 * x; }) << end_;
	auto pair_m = apply_function(_m, [](int x,float y){ return std::pair(x,y);});
	print_ << "the sume appl to map  " << pair_m.first << " , " << pair_m.second << end_;

	std::cin.get();
	return 0;
}