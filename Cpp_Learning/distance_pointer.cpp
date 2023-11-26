#include <iostream>
#include "MyLib/Console_Library/escape_code.h"

// todo make header lib file for manipulating pointer .
// distance between two pointer
template<typename P, typename Q>
int64_t ptr_diff(void* p, void* q) {
	return (P*)q - (Q*)p;
}

template<typename P,typename Q>
int64_t ptr_diff2(P* p, Q* q) {
	return (char*)q - (char*)p;
}

template<typename P,typename Q>
int64_t ptr_diff3(P* p, Q* q) {
	return reinterpret_cast<char*>(q) - reinterpret_cast<char*>(q);
}



int main()
{
	int i{ 200 }, j{ 400 };

	char c{ 'K' };

	int* pi = &i; int* pj = &j;
	char* pc = &c;

	print_ << "pointer i " << pi << end_;
	print_ << "pointer i " << pj << end_;

	print_ << "distance between is : " << ptr_diff<char, char>(pi, pj) << end_;
	print_ << "distance between is : " << ptr_diff2(pi, pj) << end_;
	print_ << "distance between is ; " << ptr_diff2(pi, pc) << end_;
	print_ << "distance between is ; " << ptr_diff2(pj, pc) << end_;
	print_ << "distance between is ; " << ptr_diff3(pj, pc) << end_;



	std::cin.get();
	return 0;
}