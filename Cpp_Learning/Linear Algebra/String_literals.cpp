#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include <ranges>

/* 
     from CppSea : Jonathan Muller
	 Lightning Talk : String Literals have the wrong type
*/

namespace tc {
	struct string_literal {
		const char* ptr;
		size_t length;

		const char* begin() const { return ptr; }
		const char* end() const { return ptr + length; }
		operator const char* () const { return ptr; }
	};
}

tc::string_literal operator""_tc(const char* ptr, std::size_t length) {
	return { ptr,length };
}

// A literal range type

namespace tc
{
	template<typename T, auto ... Ts>
	struct literal_range
	{
		static constexpr T array[] = { T(Ts)..., T(0) };

		const T* begin() { return array; }
		const T* end() { return array + sizeof...(Ts); }

		operator const T* () const { return array; }
	};
}

template<typename Str>
auto operator""_tc()
{
	return[]<std::size_t...Idx>(std::index_sequence<Idx...>) {
		using char_type = typename decltype(Str)::char_type;
		return tc::literal_range<char_type, Str[Idx]...>;
	}(std::make_index_sequence<Str.size()>{});
}

namespace tc
{
	template<typename T, auto...Ts, typename U, auto...Us>
	requires tc::has_common_type<T,U>
	auto concat(literal_range<T, Ts...>, literal_range<U, Us...>)
	{
		return literal_range<std::common_type_t<T, U>, Ts..., Us...>{};
	}
}

int main()
{
	Print_(color::Green, "size of \"abc\": ");
	print_ << std::ranges::size("abc") << end_;
	Print_(color::Red, "size include null terminator.") << end_;

	newline_;

	for (auto c : "abc")
		print_ << int(c) << end_;

	newline_;

	Print_(color::Green, "size of ");
	print_ << std::ranges::size("abc"_tc) << end_;
	for (auto c : "abc"_tc)
		print_ << int(c) << end_;

	std::cin.get();
	return 0;
}