#include <iostream>
#include <escape_code.h>


#define List \
   X(v1)     \
   X(v2)     \
   X(v3) 

#define X(value)    int value;
List;
#undef X;

void print_v(void) {
#define X(value)  print_ << #value " = " << value << end_;
	List;
#undef X
}

int main()
{



	std::cin.get();
	return 0;
}