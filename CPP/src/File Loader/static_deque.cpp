#include <iostream>
#include <optional>
#include <functional>
#include <vector>
#include <string>

#include "static_deque.hpp"


#define end_  '\n'



int main() {

	file::static_deque<std::vector<int>, 3>  deq{ {	  std::vector<int>{23,33}
													, std::vector<int>{4,3,4,5,6}
													, std::vector<int>{} } };

	std::vector<int>  vi(10, 4000);

	std::cout << "size of last vector : " << deq.at(2).size() << end_;
	std::cout << "size of first vector: " << deq.front().size() << end_;
	deq.back().push_back(23);
	std::cout << "size of first vector: " << deq.back().size() << end_;

	deq.push(vi);
	std::cout << "size of first vector: " << deq.front().size() << end_;
	std::cout << "size of first vector: " << deq.back().size() << end_;

	

	return 0;
}


int main1() {

	file::static_deque<std::string, 5>  deq{ {"one", "two", "three","four", "five"}};

	std::cout << deq.front() << end_;
	std::cout << deq.back() << end_;

	file::print_deque(deq, "display elements");
	std::cout << deq.count() << end_;

	deq.push("any number");
	deq.at(3) = "-3-";

	file::print_deque(deq, "display after modifying");
	std::cout << deq.count() << end_;

	return 0;
}




