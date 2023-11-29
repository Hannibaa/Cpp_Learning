/*
          Code collected from Mr. Mike Shah. CppCon 2021. youtube channel.
          Alexandrescu, 2001 Modern C++ Design.
          Martin Reddy's, API Design for C++.

          Author : KADDA Aoues.
          Factory Design Pattern.
*/


#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/stringfunctionhelper.h"
#include "Factory_2.h"


class I {
public:
    virtual void print() = 0;

    virtual ~I() {}
};

struct A : public I {
    int x;
    virtual void print() override { print_ << "x = " << x << end_; }
    static I* Create() { A* a = new A; a->x = RNG::Random::rand(); return a; }
};

struct B : public I {
    std::string name;
    virtual void print() override { print_ << "name : " << name << end_; }
    static I* Create() { B* b = new B; b->name = Str::getRandomString(10); return b; }
};


int main()
{
    Print_(color::Green, "Second Program v 2.0") << end_;

    MyGameObjectFactory<I, decltype(+[]()->I* {I* i; return i; }) > factory;
    //MyGameObjectFactory<I,+[]()->I* {I* i; return i; } > factory;
    //MyGameObjectFactory<I, f> factory2;
    MyGameObjectFactory<I, I* (*)(int x)> factory2;
    
    // with lambda function
    MyGameObjectFactory < I, decltype([](int x, std::string str)->I* {I* i; return i; }) >  factory3 ;

    // here why arraw of lambda function is necessary and 
    factory.RegisterObject("typeA", A{}.Create);  // Create should be static.
    factory.RegisterObject("typeB", B::Create);   // Create should be static.

    factory2.RegisterObject("typeA", +[](int x)->I* { A* a = new A; a->x = x; return a; });
    factory2.RegisterObject("typeB", +[](int x)->I* { B* b = new B;
                           b->name = "[" + std::to_string(x) + "]|" + Str::getRandomString(x); return b; });

    factory3.RegisterObject("typeA", [](int x, std::string str )->I* { A* a = new A;
                                a->x = x + int(str.size()) ; return a; });
    
    
    auto obj = factory.CreateSingleObject("typeA");
    obj->print();
    delete obj;

    obj = factory.CreateSingleObject("typeB");
    obj->print();
    delete obj;

    obj = factory2.CreateSingleObject("typeB",40);
    obj->print();
    delete obj;

    obj = factory2.CreateSingleObject("typeA",4000);
    obj->print();
    delete obj;

    obj = factory3.CreateSingleObject("typeA",4000, "hello");
    obj->print();
    delete obj;

    std::cin.get();
    return 0;
}