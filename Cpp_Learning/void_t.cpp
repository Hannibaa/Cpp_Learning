#include <iostream>
#include <vector>

/* 
                   KADDA Aoues 
				   Testing of void_t like principle
				   10 / 30 / 2023
				   HAS FUNCTION MEMBER METAFUNCTION WITH MACRO AIDE

*/


// definition of Int_t like void_t

template<class...>
using Int_t = int;

//// Macro define function and there arguments  ********************************************************
#define HAS_FUNCTION(function, arg)  template<class, class = int>                  \
                                     struct has_function_##function {              \
	                                     constexpr static bool value = false;      \
                                     };                                            \
      template<class T>                                                                         \
      struct has_function_##function<T, Int_t<decltype(std::declval<T>().##function(##arg))>> { \
           constexpr static bool value = true;                                                  \
      }                                                                                         \
//// End of Macro **************************************************************************************

//// Macro define function and there arguments  ********************************************************
#define _HAS_FUNCTION(function_name,function )  template<class, class = int>                  \
                                     struct has_function_##function_name {              \
	                                     constexpr static bool value = false;      \
                                     };                                            \
      template<class T>                                                                         \
      struct has_function_##function_name<T, Int_t<decltype(std::declval<T>().##function)>> { \
           constexpr static bool value = true;                                                  \
      }                                                                                         \
//// End of Macro **************************************************************************************

#define end_ '\n'

HAS_FUNCTION(get, );
HAS_FUNCTION(set, );
HAS_FUNCTION(push_back, 1);

_HAS_FUNCTION(PushBack, push_back(""));

//template<class T>
//struct has_function<T, Int_t<decltype(std::declval<T>().get())>> {
//	constexpr static bool value = true;
//};




// class examples

struct A {
	int get() { return 100; }
};

struct B : A {};

struct C {
	void get() { std::cout << "is it C class\n"; }
};

struct M {
	void set(int) { std::cout << " is it M class set\n"; }
	double set(float) { return 1.01; }
	std::string set() { return {}; }
};

int main() {

	static_assert(has_function_get<C>::value);
	static_assert(has_function_set<M>::value);

	static_assert(has_function_push_back<std::vector<float>>::value);
	static_assert(has_function_PushBack<std::vector<A>>::value);

	std::cout << " has this function " << end_;

	std::cin.get();
	return 0;
}