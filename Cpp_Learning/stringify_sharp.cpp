#include <iostream>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"

#define STR(x,y)      x##y
 
#define Text(x)       "hello"#x"!!!"
#define Var(x)        __##x
#define _Member(x)    m_##x
#define _Get(x)       get##x##_
#define _Set(x,y)     set##x##_##y

#define TYPEFUNC(T,F)    T##::##F 

using namespace std;

int _Get(Value)(int x) {
	return x;
}

void _Set(Value, x)(int x) {

}

int main()
{
	int STR(Var, 1) {};


	STR(std, ::string) str11("hello");
	TYPEFUNC(std, string);

	float Var(f) {};
	std::string _Member(Name)("Kadda");

	std::string str(Text(world!));

	print_ << Text(world) << end_;
	print_ << str << end_;
	print_ << m_Name << end_;

	print_ << "function " << getValue_(400) << end_;

	cin.get();
	return 0;
}