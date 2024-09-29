#include <iostream>
#include <vector>
#include <optional>
#include <functional>

#define end_  '\n'


template<typename T, typename U>
std::optional<T> f(std::optional<U> x) {


	if (x.has_value()) {

		x.value() = x.value() * x.value();
	}

	return std::optional<float>(static_cast<T>(x.value()));

}

template<typename T>
requires std::is_arithmetic_v<T>
std::optional<T> operator+(const std::optional<T>& v1, const std::optional<T>& v2) {
	return std::optional<T>(v1.value() + v2.value());
}

// function that return function
template<typename T,typename U, template<typename > class Monoid >
std::function<Monoid<T>(U)> append(
	std::function<Monoid<T>(U)>  f1,
	std::function<Monoid<T>(U)>  f2
) {
	return [f1, f2](U x) {return f1(x) + f2(x); };
}


template<typename T, template<typename> class Functor >
void Apply(Functor<T>& F, T x) {
	F.push_back(x);
}

template<typename A, typename B, template<typename> class Functor>
Functor<B> map(std::function<B(A)> f, const Functor<A>& y) {

	Functor<B> result;

	for (const auto& e : y)
		Apply(result, f(e));

	return result;
}




int main() {

	std::optional v1 = 34;
	std::optional v2 = 55;

	auto v = v1 + v2;


	std::cout << " :: " << f<float>(std::optional(345)).value() << end_;
	std::cout << " :: " << f<int>(std::optional(3.f)).value() << end_;

	std::cout << " v " << v.value() << end_;

	auto f1 = [](float x)->std::optional<int> {return std::optional<int>(int(x)); };
	auto f2 = [](float x)->std::optional<int> {return std::optional<int>(int(x)); };

	std::cout << append<int,float,std::optional>(f1, f2)(123.f).value();

	std::vector<int> v{ 3,5, 7 };

	auto f = [](int x) ->float { return float(x); };

	auto xv = map<int,float,std::vector>(f, v);


	return 0;
}