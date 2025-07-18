//				Exemple of using generic programming


#pragma once
#include <cmath>

namespace vector {

	template<typename Vector, typename T = typename Vector::value_type>
	requires std::is_arithmetic_v<T>
	T Norm(const Vector& v) {

		return std::sqrt(v.x * v.x + v.y * v.y);
	}



}
