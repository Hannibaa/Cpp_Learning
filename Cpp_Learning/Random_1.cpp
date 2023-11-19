#include <iostream>
#include <random>
#include <vector>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/stringfunctionhelper.h"
#include "MyLib/random_generator.h"

/*
        trying to make vector of 
*/




int main()
{
	std::random_device  rd("first");
	std::vector<std::random_device> vec_rd(10);

    std::vector<RNG::Random> vec_rand;

	for (int i = 0; i < 10; ++i) {
		//vec_rd.push_back(std::random_device{}); // error C2280 deleted function.
        vec_rand.push_back(RNG::Random{Str::getRandomString(10)});
	}
	int i{};
	for(auto& r : vec_rd )
	print_ << "value of random " << ++i << " : " << r() << end_;

    i = 0;
    for (auto r : vec_rand)
        print_ << "random : " << r.name() << ", " << ++i << " : " << r() << end_;
	
	print_ << "end \n";

	std::cin.get();
	return 0;
}