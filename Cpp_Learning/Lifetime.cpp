#include <iostream>
#include "life_time.h"

#define end_ '\n'
#define Line cout << "---------------------------------------------------------------------\n"
#define wait_ std::cin.get()
#define print std::cout 

using namespace std;

template<typename T>
void f(const T&) { puts("call function f(const T&) "); }
template<typename T>
void f1(T) { puts("call function f(T)"); }

int main()
{
	Lifetime l;
	//Lifetime* ptr = &l;

	//ptr = nullptr;

	//ptr = new Lifetime[1];

	//delete[]ptr;

	f(l);

	f1(Lifetime{});

	cin.get();
	return 0;
}