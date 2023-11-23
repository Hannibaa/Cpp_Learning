#include <iostream>

#define print_  std::cout 
#define end_    '\n'


class A {

    int (*function)(int);

public:
    //A(int (*f)(int))
    //    : function{ f }
    //{}

    int operator()(int x) {
        return function(x);
    }
};



class B {
    int x;
public:

    int operator()() { return x; }
};

template<typename T>
class D {
    T x;
public:
    T operator()() const noexcept { return x; }
    T& operator()() noexcept { return x; }
};

class K {

    int (*function)(int);

public:

    auto& operator()() { return function; }   // try without reference :compilation error lvalue.

    int operator()(int x) { return function(x); }

    void operator()(int (*f)(int)) { function = f; }
};

int main() {

 //   A a([](int x)->int {return 1000; });
    A a;

   // print_ << a(200) << end_;  // this will access violation

    B b;                      // this will gave garbage memory .

    print_ << "b member value without initialization : " << b() << end_;

    D<float> d;

    print_ << "return member without initialization : " << d() << end_;
    d() = 110.23f;
    print_ << "after initialization by operator() " << d() << end_;

    K k;

    //print_ << k(100) << end_;   // access violation

    k() = [](int x)->int {return 200; };

    print_ << "initialized function by referencing" << k(100) << end_;

    k([](int x) {return 3 * x; });

    print_ << "changing function : triple x " << k(10) << end_;


    return 0;
}