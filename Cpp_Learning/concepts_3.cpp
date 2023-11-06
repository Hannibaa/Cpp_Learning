#include <iostream>
#include <MyLib/containers.h>
#include "MyLib/Console_Library/escape_code.h"
#include <MyLib/Headers/my_concepts.h>


// using if constexpr (requires())
template<typename Container, typename T>
void  PushBack0(Container& c, const T& value) {
	if constexpr (requires { c.push_back(value); }) {
		c.push_back(value);
	}
	else c.insert(value);
}


// using if constexpr (Logical concept )
template<typename Container, typename T>
void PushBack1(Container& c,const T& value) {
	if constexpr (HasPushBack<decltype(c), decltype(value)>) c.push_back(value);
	else c.insert(value);
}

// using another logical concept and removing const volatile reference from decltype
template<typename Container, typename T>
void PushBack2(Container& c, const T& value) {
	if constexpr (HasPushBack2<std::remove_cvref_t<decltype(c)>>) { // here also
		c.push_back(value);                                         // remove ref
	}
	else
		c.insert(value);
}


// solve problem by removing cvref from a type 
template<typename Container, typename T>            // probleme with HasPushBack3 and 2.
void PushBack3(Container& c, const T& value) {      // probleme fixed to remove reference cv.
	if constexpr (HasPushBack3<std::remove_cvref_t<decltype(c)>>) {
		c.push_back(value);
	}
	else
		c.insert(value);
}

template<typename C1,typename T1, typename C2, typename T2, typename C3 , typename T3>
using PushBack_funcs = std::tuple<void(*)(C1&, const T1&), void(*)(C2&, const T2&), void(*)(C3&, const T3&)>;


int main()
{
	std::string str;
	std::vector<const char*> c_string;
	std::vector<int> vec_int;
	std::set<float> set_float;
	std::multiset<int> mset_int;

	std::string::value_type k{};


	// test all container for have push back or no

	// test for string
	PushBack0(str, 'A'); 
	str.push_back('B'); 
	PushBack1(str, 'C');
	PushBack2(str, 'D');
	PushBack3(str, 'D');

	// test for vector of c_string
	PushBack0(c_string, "hello");
	c_string.push_back(" world");
	PushBack1(c_string," !.");
	PushBack2(c_string, " end");
	PushBack3(c_string, " ***");

	// vector of integer
	PushBack0(vec_int, 23);
	vec_int.push_back(40); 
	PushBack1(vec_int,40);
	PushBack2(vec_int,60);
	PushBack3(vec_int, 500);

	// set of float
	PushBack0(set_float, 4.5f);
	set_float.insert(6.77f);
	PushBack1(set_float,4.5f);
	PushBack2(set_float,41.5f);
	PushBack3(set_float,45.5f);


	// multiset of int
	PushBack0(mset_int, 2000);
	mset_int.insert(2000);
	PushBack1(mset_int,3000);
	PushBack2(mset_int, 4000);
	PushBack3(mset_int, 7000);

	// affich all value
	vu::print_container(str, "string container :");
	newline_;
	vu::print_container(c_string, "vector of const char* c string :");
	newline_;
	vu::print_container(vec_int, "vector of int");
	newline_;
	print_ << "size of set : " << set_float.size() << end_;
	vu::print_container(set_float, "set of float :");
	newline_;
	print_ << "size of set : " << mset_int.size() << end_;
	vu::print_container(mset_int, "multiset of int :");

	std::cin.get();
	return 0;
}