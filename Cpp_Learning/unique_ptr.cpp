#include <vector>
#include <thread>
#include <random>
#include <algorithm>
#include <memory>
#include <iostream>

// define what exemple you will need here:
#define __exemple2

#ifdef __exemple2
// very very bad program. 
std::thread  thr;
int count{};

int main() {

	std::cout << "main thread id " << std::this_thread::get_id() << '\n';

	thr = std::thread(main);

	if (++count < 10) {
		std::cout << "end of thread \n";
		return 0;
	}

	thr.join();
	std::cout << "end of program \n";
	return 0;
}

#endif // exemple2


#ifdef  __exemple1


std::vector<std::jthread> runners(4);

int main()
{
	// sample data generation
	std::vector<uint32_t> data_in;
	std::mt19937 rng;
	std::generate_n(std::back_inserter(data_in), 2, std::ref(rng));

	// create shared pointer from vector.
	// Note the const, making the data immutable.
	auto shared =
		std::make_shared<const std::vector<uint32_t>>(std::move(data_in));

	// start thread , giving each thread a copy of the shared_ptr
	for (auto& thread : runners) {
		thread = std::jthread([shared]() {
			// accessing const - methods of STL containers is thread safe
			for (auto v : *shared) {
				// process data
				std::cout << v << "thread id " << std::this_thread::get_id() << '\n';
			}
			});
	}

	// 4 runners threads are all running, but the locale reference 
	// to the data is no longer held.

	// The data will be released once all runners finish, thus releasing
	// their references to the data, i.e. the ref-count reaches zero.

	// std::jthread auto-joins on destruction, or we can do it explicity :

	for (auto& thread : runners)
		thread.join();

	return 0;
}

#endif