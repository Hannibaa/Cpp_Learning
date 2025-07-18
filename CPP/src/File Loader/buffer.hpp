#pragma once
#include <iostream>
#include <vector>
#include <string_view>

#define   end_				'\n'


namespace file {
	
	// buffer as base of standard vector
	// define buffer for typed of size size
	template<typename T>
		requires std::is_pod_v<T>
	struct Buffer : std::vector<T> {
		using std::vector<T>::vector;
	};



	// printing buffer of type T
	template<typename T>
	requires std::is_pod_v<T>
	void print_buffer(const Buffer<T>& buffer, std::string_view comment) {
		std::cout << comment << end_;
		for (const auto& e : buffer)
			std::cout << e << " ";
		std::cout << end_;
	}


}