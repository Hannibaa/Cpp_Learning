#include <iostream>
#include <Windows.h>
#include <include/console/escape_code.h>

namespace units {
	struct m {
		unsigned long long int value;
		friend auto operator <=>(const m&, const m&) = default;
	};

	struct km {
		unsigned long long int value;
		operator m() const { return { value * 1000 }; }
		friend auto operator<=>(const km&, const km&) = default;
	};
}

constexpr units::km operator"" _km(unsigned long long int v) {
	return { v };
}

constexpr units::m operator"" _m(unsigned long long int v) {
	return { v };
}



int main() {
	set_escape_mode;
	Print_(color::Green, "Begin Program") << end_;

	if (100_m < 1_km) {
		Print_(color::Red, "100m is less than 1km") << end_;
	}

	if (1001_m > 1_km) {
		Print_(color::Fuchsia, "1001m is more than 1km") << end_;
	}



	Print_(color::Green, "End   Program") << end_;
	return 0;
}
