#include <iostream>
#include <vector>
#include "MyLib/Console_Library/escape_code.h"

template<typename T>
using Vec = std::vector<T>;

using CharVec = Vec<char>;


template<int N>
struct _2N {
	//  0..8 = 8, 9..16 = 16, 17..32 = 32, 33..64 = 64.
	constexpr int operator()() const noexcept {
		if (N > -1 && N < 9) return 8;
		if (N > 8 && N < 17) return 16;
		if (N > 16 && N < 33) return 32;
		if (N > 32 && N < 65) return 64;
	}

	constexpr operator int() const noexcept {
		return _2N<N>()();
	}
};

template<int N>
constexpr int _2n = _2N<N>();


template<int N>
struct Int {
	
	long long i : N;

	Int() = default;

	template<typename T>
	Int(const T& _i ) : i{ static_cast<long long>(_i) } {}

	using type = Int<N>;

	constexpr operator long long() const noexcept { return i; }
};

template<>
struct Int<8> {
	using type = char;
};

template<>
struct Int<16> {
	using type = short;
};

template<>
struct Int<64> {
	using type = long long int;
};

template<int N>
using Int_t = typename Int<N>::type;

int main()
{
	Vec<char> vec_char;
	Vec<float> vec_float;

	Int_t<3> i;
	Int_t<8> c;

	//Int_t<_2n<11>> g;

	i = 0b11100;


	for (int k = 0; k < 30; ++k) {
		i = k;
	     print_ << "int i is " << i << end_;
		 wait_;
	}

	static_assert(_2N<35>() == 64);
	static_assert(_2n<17> == 32);
	static_assert(_2n<64> == 64);

	print_ << "test _2N " << _2N<34>()() << end_;
	print_ << "test 2 _2N : " << _2N<11>() << end_;
	print_ << "test 3 _2n : " << _2n<13> << end_;
	print_ << "test 4    : " << _2n<'a'> << end_;

	std::cin.get();
	return 0;
}