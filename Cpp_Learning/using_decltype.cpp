#include <iostream>


const int& get(const int& x) {

	int i = 300;

	return x;
}

const auto& get2(int x) {
	return x;
}

const int& set(const int& x) {
	return x;
}


decltype(auto) get_value()  {
	int i = 33;  
	return i;    // <------------ and ---|           
}                                  //    |
                                   //    |----> this parenthesis change a type???
 decltype(auto) get_value_ref() {  //    |
	int i = 33;                    //    |
	return (i); // <------------ here ---|
}


int main() {
	// the function ; const int& get(const int& x);
	// auto k = get(200);       // deduce :   int;
	// const auto k = get(300); // deduce :   const int;
	// auto& k = get(600);  // deduce : const int&;
	// auto k = get2(100);     // deduce : int;
	// const auto k = get2(300);  // deduce : const int;


	// auto get_value() ->decltype(auto) { int i =33; return (i);}
	// decltype(auto) k = get_value();  // deduce  : int&

	// auto get_value() ->decltype(auto) { int i = 22; return i;}
	// decltype(auto) k = get_value();    // deduce : int

	// decltype(auto) k = get_value();       // deduce : int

	// auto get_value() { int i = 23; return i;}
	// decltype(auto) k = get_value();    // deduce : int

	// decltype(auto) get_value() {int i = 33; return i;}
	
	decltype(auto) k = get_value();

	static_assert(std::is_same_v< decltype(k),int>);
		                           
	


	std::cin.get();
	return 0;
}