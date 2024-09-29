#include <iostream>
#include <vector>
#include <Windows.h>
#include <memory>
#include <ranges>

#include <include/console/escape_code.h>


template<std::bidirectional_iterator It, std::sentinel_for<It> Sentinel>
void reverse(It begin, Sentinel end) {
	while (begin != end) {
		end = std::prev(end);
		if (end == begin) break;
		// using iter_swap to swap the values behind the iterator
		std::iter_swap(begin, end);
		begin = std::next(begin);
	}
}

template<typename iter>
void print_v(iter it) {
	for (auto iit = it.begin(); iit != it.end(); ++iit)
		Print_(color::Grey, *iit) << " , " ;
	print_ << end_;
}

int main() {
	Print_(color::Green, "Begin Program") << end_;

	std::vector<int> vi{ 1,3,5,7,9 };
	print_v(vi);

	reverse(vi.begin(), vi.end());

	print_v(vi);


	Print_(color::Green, "End   Program") << end_;
	return 0;
}