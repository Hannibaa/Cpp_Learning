#include <iostream>
#include <bit>

#define end_ '\n'

uint32_t make_mask(int Nbits) {
	return (1u << Nbits) - 1;
}

template<int Nbits>
requires (Nbits >= 0) && (Nbits < 32)
constexpr uint32_t _mask = (1u << Nbits) - 1;

template<int N, typename T>
constexpr T _power2 = static_cast<T>(1ull << 1);


int main()
{
	int var_int = 31;
	constexpr int n = 31;

	constexpr int N = -1;
	constexpr unsigned int uN = -1;

	constexpr auto x_int = 1 << n;
	constexpr auto x_uint = 1u << n;
	constexpr auto x_ull = 1ull << n;
	constexpr auto x_ul = 1ul << n;

	std::cout << std::hex << uN << end_;
	std::cout << std::hex << make_mask(var_int) << end_;
	std::cout << std::hex << _mask<31> << end_;
	// _mask<31> = 1; // if we don't have const specifier it s variable ;
	std::cout << std::hex << _mask<31> << end_;
	_mask<3>;

	std::cout << "power of 2 : " << _power2<34, uint32_t> << end_;
	std::cin.get();
	return 0;
}