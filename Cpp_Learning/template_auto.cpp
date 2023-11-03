#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

template<typename ...Ts>
struct list {};

template<auto T0,decltype(T0)...T>
constexpr decltype(auto) add() { return 1 + sizeof...(T); }

template<auto T0,decltype(T0)...Ts>
list<decltype(T0), decltype(Ts)...> get() { return {}; }

template<auto...vals>
list<decltype(vals)...> list_of() { return {}; }

//template<auto...vals,typename...Ts>   // not work but we keep it
//list<decltype(vals)..., Ts...> list_of_all() { return list{}; }

//template<auto...vals,typename...Ts>
//int get_number_of_args_template() { return sizeof...(vals)+sizeof...(Ts); }

template<auto val,typename T>
constexpr bool is_same_type() { return std::is_same_v<decltype(val), T>; }


template<decltype(auto) N,typename T0>
struct thisthis{};




int main()
{
	thisthis<4.5, std::string>  cl;

	auto List = get<1,2,9>();

	auto List2 = list_of<1, 'q', 3.5f, 5.66>();

	// auto List3 = list_of_all<1, 4.f, 5.44, int , char>(); // not work!!!!

	//auto sz = get_number_of_args_template<1, 3.5, 5.1f, int, char, double>();// not work!!!

	auto b = is_same_type<3, int>();

	int x{ 44 };

	// b = is_same_type<x, int>(); // not working! variable type.


	print_ << "is it same type : " << is_same_type<4.55,float>() << end_;

	print_ << "number of element of : " << add<1, 2, 4i64>() << end_;

	std::cin.get();
	return 0;
}