#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/my_metaprog.h"


template<typename T0, typename...Ts>
constexpr T0 get_first(T0 t0, Ts...ts) {
	return t0;
}



template<typename R, typename T>
constexpr R f(const T& x) noexcept { return static_cast<R>(x); }

template<typename R, typename...Ts>
constexpr R h(Ts...ts) { return static_cast<meta::first_type_t<Ts...>>(get_first(ts...)); }

template int f<int>(float);

int g(float) { return 100; }

int main()
{
	print_ << "value : " << f<int>(200.89f) << end_;
	
	print_ << "value first :" << get_first(23, 'c', 3.44, 5.6f, "shsfsfs") << end_;

	print_ << "value of h " << h<int>('c', 343, 4.f, 4.44) << end_;

	std::_Function_args<decltype(g)>::_Unnameable_result   x;
	std::_Function_args<decltype(g)>::_Unnameable_argument y;

	std::_Function_args<decltype(f<int, float>)>::_Unnameable_argument xx = 23.f;
	std::_Function_args<decltype(f<char, short>)>::_Unnameable_result   yy{};

	/*
	*   make function overloading by concept 
	*    requires in typename mapped_type and value_type alone. 
	*/

	std::cin.get();
	return 0;
}