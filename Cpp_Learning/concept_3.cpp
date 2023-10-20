#include <iostream>
#include <MyLib/containers.h>
#include "MyLib/Console_Library/escape_code.h"
#include <MyLib/Headers/my_concepts.h>


template<typename Container, typename T>
void push_back(Container& c, const T& value) {
	if constexpr (requires { c.push_back(value); }) {
		c.push_back(value);
	}
	else c.insert(value);
}

template<typename Container, typename T>
void PushBack(Container& c,const T& value) {
	if constexpr (HasPushBack<decltype(c), decltype(value)>) c.push_back(value);
	else c.insert(value);
}

template<typename Container, typename T>
void PushBack2(Container& c, const T& value) {
	if constexpr (HasPushBack2<std::remove_cvref_t<decltype(c)>>) { // here also
		c.push_back(value);                                         // remove ref
	}
	else
		c.insert(value);
}

template<typename Container, typename T>            // probleme with HasPushBack3 and 2.
void PushBack3(Container& c, const T& value) {      // probleme fixed to remove reference cv.
	if constexpr (HasPushBack3<std::remove_cvref_t<decltype(c)>>) {
		c.push_back(value);
	}
	else
		c.insert(value);
}

template<typename Container,typename T>
using vec_func = std::vector<void(*)(Container&, const T&)>;


int main()
{
	std::string str;
	std::vector<const char*> c_string;
	std::vector<int> vec_int;
	std::set<float> set_float;
	std::multiset<int> mset_int;

	std::string::value_type k{};

	vec_func<std::string,char>  v{ &PushBack2<std::string,char>};

	// test all container for have push back or no
	push_back(str, 'A'); str.push_back('B'); PushBack(str, 'C'); PushBack2(str, 'D');
	PushBack3(str, 'D');
	push_back(c_string, "hello"); c_string.push_back(" world"); PushBack(c_string," !.");
	PushBack(c_string, " end");
	push_back(vec_int, 23); vec_int.push_back(40); PushBack(vec_int,40);
	PushBack3(vec_int, 500);
	push_back(set_float, 4.5f); set_float.insert(6.77f); PushBack(set_float,4.5f);
	push_back(mset_int, 2000); mset_int.insert(2000); PushBack(mset_int,3000);
	PushBack2(mset_int, 4000);
	PushBack3(mset_int, 7000);

	// affich all value
	vu::print_container(str);
	newline_;
	vu::print_container(c_string);
	newline_;
	vu::print_container(vec_int);
	newline_;
	print_ << "size of set : " << set_float.size() << end_;
	vu::print_container(set_float);
	newline_;
	print_ << "size of set : " << mset_int.size() << end_;
	vu::print_container(mset_int);

	std::cin.get();
	return 0;
}