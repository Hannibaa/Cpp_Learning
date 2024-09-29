

int f(int x) {
	return x;
}


template<typename T>
T add(T x, T y) {
	return x + y;
}

template<typename T>
	requires requires(T x, T y) { x* y; }
constexpr T mult(T x, T y) {
	return x * y;
}