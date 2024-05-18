#include <iostream>
#include <valarray>
#include <functional>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/random_generator.h"

template<typename T>
requires std::is_arithmetic_v<T>
constexpr T power2(const std::valarray<T>& v) {
	T s{};
	for (const auto& x : v) s += x * x;

	return s;
}

template<typename T, typename Function>
requires std::is_arithmetic_v<T>
constexpr T apply_func(const std::valarray<T>& v, Function f) {
	T s{};
	for (const auto& x : v) s += f(x);

	return s;
}

template<typename T, typename Function, typename Operation>
// contrain of Function int(int) and 
// constrain on operation as binary operation int(int,int)
requires std::is_arithmetic_v<T>
constexpr T apply_func(const std::valarray<T>& v, Function f, Operation op) {
	T s{};
	for (const auto& x : v) s = op(s, f(x));
	return s;
}

int main() {

	std::valarray<int>   v(10);
	
	rng::iRG<int>   irand;

	for (int i = 0; i < v.size() ; ++i) v[i] = irand(0,5);

	for (auto e : v) print_ << e << end_;

	print_ << "maxi : " << v.max() << end_;
	print_ << "mini : " << v.min() << end_;
	print_ << "sum  : " << v.sum() << end_;

	print_ << "quadratic : " << power2(v) << end_;
	print_ << "quadratic : " << apply_func(v, [](int x) {return x * x * x; }) << end_;
	print_ << "sfsfsdf : ' " << apply_func(v, [](int x) {return 3 * x; }, [](int x, int y) {return x - y; }) << end_;

	print_ << "end program\n";
	wait_;
	return 0;
}