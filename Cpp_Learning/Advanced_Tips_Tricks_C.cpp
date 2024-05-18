/*
     Advanced trick and tips from video in  youtube.com

*/

#include <iostream>

#define     end_                        '\n'

// 1. count the number of element of array 
#define     NUMBER_ELEMENT(Array)       ((sizeof(Array))/sizeof((Array)[0]))

// 2. Macro UNIQ use unique name for a variable
#define   ___UNIQ(name, n)                  name##n
#define    __UNIQ(name, n)                  ___UNIQ(name,n)
#define     _UNIQ(name, n)                  __UNIQ(name,n)
#define      UNIQ(name)                  _UNIQ(name,__LINE__)

// 3. Macro Process an array statically
#define   STATIC_ARRAY_FOREACH(item, Array)        \
          for(size_t keep = 1, index = 0;          \
          keep && index < NUMBER_ELEMENT(Array)  ; \
          keep = !keep, index++)                   \
          for (item = &Array[index] ; keep ; keep = !keep )

// 4. Static Assert 
//#define   STATIC_ASSERT(COND, MSG)     typedef  char \ 
//               static_assertion_##MSG[(COND) ? 1 : -1]

// 5. Quote any thing
#define    QUOTE(X)         #X
#define    _S(X)            QUOTE(X)
#define    _WS(X)           L#X


template<typename T>
void prt_n_element(T& t, std::string_view comment) {
    std::cout << "number of element " << comment  << " : " << NUMBER_ELEMENT(t) << end_;
}



// the origine of this
class A {
    int i;
public:
    int get() const {
        return i;
    }

    void set(int x) {
        this->i = x;
    }

    void set_(A* This, int x) {
        This->i = x;
    }
};

int main() {

    A z;
    z.set(34);
    std::cout << z.get() << end_;

    z.set_(&z, 50);
    std::cout << z.get() << end_;

    return 0;
}


int main5() {
    int x{};
    int var{};

    std::cout << "hello " << _S(world) << end_;
    std::cout << "hello " << _S(x) << end_;
    std::cout << "hello " << QUOTE(x) << end_;
    std::wcout << L"hello" << _WS(world) << end_;
    return 0;
}

int main4() {

   //STATIC_ASSERT(2 > 1, " 2 sup 1");

    return 0;
}

int main3() {

    const char* vstr[] = {
        "Hello",
        "Kadda",
        "here"
    };

    STATIC_ARRAY_FOREACH(const char** ptr, vstr)
    {
        std::cout << *ptr << end_;
    }

    return 0;
}

int main2() {

    int x = 200;

    int    UNIQ(x){};
    int    UNIQ(x);
    int    UNIQ(x){};

   // std::cout << x << " " << x29 << " " << x31 << " " << x31 << end_;

    return 0;
}

int main1() {

    char c[3]{};

    std::string   str[4]{};

    const char* c_str = "1234";

    int* array_int = new int[5] {0,1,2,3,4};


    std::cout << "number of element c         : " << NUMBER_ELEMENT(c) << end_;
    std::cout << "number of element str       : " << NUMBER_ELEMENT(str) << end_;
    prt_n_element(c_str, "c_str");
    std::cout << "number of element c_str       : " << NUMBER_ELEMENT(c_str) << end_;
    // here is not applicable and always will gave you 2 or 1? 
    // allocation in heap not stack.
    std::cout << "number of element array_int : " << NUMBER_ELEMENT(array_int) << end_;

    delete[] array_int;
    return 0;
}