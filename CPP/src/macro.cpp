#include <iostream>
#include <include/Macros.hpp>

#define end_				'\n'

#define EXPAND(var1, ...)     var1 << EXPAND(__VA_ARGS__)


#define PRINT(...)			std::cout << EXPAND(__VA_ARGS__) << end_

int main() {

	return 0;
}