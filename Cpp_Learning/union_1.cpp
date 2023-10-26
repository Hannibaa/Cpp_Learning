#include <iostream>
#define end_ '\n'

union X2 {
	int a;
	float b;

	X2(int a) : a{ a } {}
	X2(float b) : b{b} {}

};



template<typename T1, typename T2>
union Xunion {
	T1 value1;
	T2 value2;

	Xunion(T1 t1) : value1{ t1 } {}
	Xunion(T2 t2) : value2{ t2 } {}
};

template<typename To_, typename From_>
requires (sizeof(To_) == sizeof(From_)) && std::conjunction_v<std::is_trivially_copyable<To_>,
                                                              std::is_trivially_copyable<From_>>
									    && (!std::is_pointer_v<To_>)
									    && (!std::is_pointer_v<From_>)
To_ to_(From_ from) {
	//Xunion<To_, From_> x{ from };
	return Xunion<To_, From_>{from}.value1;
}



float to_float(int x) {
	X2 x2(x);
	return x2.b;
}

int to_int(float y) {
	X2 x2(y);
	return x2.a;
}




int main()
{
	union X1 {
		int a;
		float b;
	} A{233}, B{4.5f};

	std::cout << " Print A  int[" << A.a << "] float[" << A.b << "]\n"; // here will initialize to int
	std::cout << " Print B  int[" << B.a << "] float[" << B.b << "]\n";  // implicite conversion to int.

	X2 A2(233), B2(4.5f);

	std::cout << "\nUnion with constructor to distincter which type \n";

	std::cout << " Print A2  int[" << A2.a << "] float[" << A2.b << "]\n"; // here will initialize to int
	std::cout << " Print B2  int[" << B2.a << "] float[" << B2.b << "]\n\n";  // implicite conversion to int.

	std::cout << "Function conversion float <--> int : " << end_;

	std::cout << "convert int 1 to flaot " << to_float(1) << end_;
	std::cout << "convert 1.f float to int " << to_int(1.f) << end_;

	std::cout << "\nTest new function \n";
	std::cout << "convert size_t 1 to double " << to_<double>(1i64) << end_;
	std::cout << "convert 1 double to int64 : " << to_<int64_t>(1.0) << end_;

	// to_<std::string>(std::string{ "he" });// not compile
	float ff = 3.4f;
	float* f = &ff ;
	// std::cout << "conver pointer ???? " << to_<int*>(f) << end_;  // not working is pointer

	std::cin.get();
	return 0;
}