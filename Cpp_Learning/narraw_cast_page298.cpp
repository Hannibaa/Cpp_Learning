#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

template<typename To, typename From>
auto narraw_cast(const From& from) {

	To to = static_cast<To>(from);

	if (from == static_cast<from>(to)) {
		return to;
	}
	else {
		Print_(color::Red, "Not equal casting") << end_;
		return {};
	}

}

int main()
{



	wait_;
	return 0;
}