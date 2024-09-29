#include <iostream>
#include <forward_list>


template<typename T>
void swap_tofront(std::forward_list<T>& list,const T& element)
{
	// check element if is it not in front
	if (list.front() != element) {

		// create two current and previous iterator
		std::forward_list<int>::iterator  prev = list.before_begin();
		auto curr = list.begin();

		// find element and it's previous element 
		while (curr != list.end() && *curr != element)
		{
			prev = curr;
			++curr;
		}

		// if element fond move it to front
		if (curr != list.end())
		{
			// remove the element from its current position
			list.erase_after(prev);
			// insert the element at the front
			list.push_front(element);
		}
	}
}






int main() {

	std::forward_list<int> list{ 23,30,40,50,100,60,40,10 };

	// elemnet to be placed in front 
	int element = 100;

	swap_tofront(list, element);

	//list.remove(element);
	//list.push_front(element);

	for (const auto& e : list) std::cout << e << " ";

	return 0;
}