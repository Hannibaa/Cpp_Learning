/*
     RETURN TYPE RESOLVER

     Intent : To deduce the type of the variable being initialized or assigned to.

     Motivation : The type of the variable being initialized can be a useful information
                  to have in certain contexts. Consider, for instance, we want to initialize
                  STL containers with random numbers. However, we don't know the exact type
                  of the container expected by the user. It could be std::list, std::vector
                  or something custom that behaves like STL container.
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>


#define end_ '\n'

template<typename Container>
void print_container(const Container& c, std::string_view comment = "") {
    std::cout << comment << end_;
    for (auto& e : c)
        std::cout << e << " ";
    std::cout << end_;
}



//#define RTR_1
#define RTR_2

#ifdef RTR_2
   
class getRandomN {
    size_t count;

public:
    getRandomN(size_t n = 1): count(n) {}

    template<typename Container>
    operator Container () {
        Container c;

        for (size_t i = 0; i < count; ++i) {
            c.insert(c.end(), rand());       // push_back !
        }

        return c;
    }
};



int main() {

    std::vector<int> vi = getRandomN(10);

    std::list<int> li = getRandomN(5);

    print_container(vi, "vector");
    print_container(li, "list");

    std::cout << "end of program" << end_;
    std::cin.get();
    return 0;
}

#endif

#ifdef RTR_1

template<typename Container>
Container  getRandomN(size_t n) {
    Container c;

    for (size_t i = 0; i < n; ++i) {
        c.insert(c.end(), rand()); // push_back is not supported by all container
    }

    return c;
}


int main() {

    std::list<int>  rl = getRandomN<std::list<int>>(10);
    auto rr  = getRandomN<std::vector<int>>(5);

    print_container(rl, "list");
    print_container(rr, "vector");

    std::cout << "End of program" << end_;
    std::cin.get();
    return 0;
}

#endif // RTR_1