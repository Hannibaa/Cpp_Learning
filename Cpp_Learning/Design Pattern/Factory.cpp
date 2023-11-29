/*
          Code collected from Mr. Mike Shah. CppCon 2021. youtube channel.
          Alexandrescu, 2001 Modern C++ Design.
          Martin Reddy's, API Design for C++.

          Author : KADDA Aoues.
          Factory Design Pattern.
*/

#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "Factory_1.h"
#include "MyLib/stringfunctionhelper.h"

class I {
public:
    virtual void print() = 0;

    virtual ~I() {}
};

struct A : public I {
    int x;
    virtual void print() override { print_ << "x = " << x << end_; }
};

struct B : public I{
    std::string name;
    virtual void print() override { print_ << "name : " << name << end_; }
};


int main()
{
    MyGameObjectFactory<I> factory;

    // here why arraw of lambda function is necessary and 

    factory.RegisterObject("typeA", []()->I* { A* a = new A; a->x = std::rand(); return a; });
    factory.RegisterObject("typeB", []()->I* { B* a = new B; a->name = Str::getRandomString(10) ; return a; });

    auto obj = factory.CreateSingleObject("typeA");
    obj->print();
    delete obj;
    obj = factory.CreateSingleObject("typeB");
    obj->print();
    delete obj;

	std::cin.get();
	return 0;
}