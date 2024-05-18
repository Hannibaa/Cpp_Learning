/*
                                         CRTP : Curiously Recurring Template Pattern
    Intent : 
        To specialize a base class using the derived class as a template argument.

    Also known as : 
        1. Mixin-form-above
        2. Static polymorphism
        3. Simulated dynamic binding
        4. Upside-down inheritence

    Motivation : 
        To extract out a type independent but type customizable functionality in a base class
        and to mix-in that interface/property/behavior into a derived class, customized for
        the derived class.
*/

#include <iostream>
#include <atomic>


//    template<typename Derived>
//    struct Base {};
//    
//    struct Derived1 : Base<Derived1>{};
//    
//    struct Derived2 : Base<Derived2> {};


//#define DYNAMIC_POLY
//#define STATIC_POLY
#define CRTP_LIMIT_
#define end_  '\n'

// Dynamic polymorphism

#ifdef DYNAMIC_POLY 


struct Base {

    void executed() {
        interface();
    }

protected:
    virtual void interface() = 0 {
        // the default implementation man be (if exists) or should be (otherwise)
        // Overriden by inheriting in derived classes (see below)
        std::cout << "Base Interface" << end_;
    }
};

// Derived 1
struct Derived1 : Base {
    // this class uses variant of interface
    // void interface() override
    void interface() override {
        std::cout << "Derived 1 Class Override" << end_;
    }
};

// Derived 2
struct Derived2 : Base {
    // This class overrides interface with own implementation
    void interface() override {
        // implementation
        std::cout << "Derived 2 Class Override" << end_;
    }
};


int main() {

    std::cout << "Exemple on dynamic polymorphism" << end_;

    Base* base1 = new Derived1;
    Base* base2 = new Derived2;

    // cast from Base* to Derived1:
    Derived1 d1 = *static_cast<Derived1*>(base1);

    Derived2 d2 = *dynamic_cast<Derived2*>(base2);

    base1->executed();
    base2->executed();

    std::cout << "cast : d1 " << end_;

    d1.executed();

    std::cout << "cast : d2 " << end_;

    d2.executed();

    delete base1;
    delete base2;

    return 0;
}

#endif // DYNAMIC_POLY

#ifdef STATIC_POLY

template<typename ConcreteAnimal>
struct IAnimal {
    void sayHello() {
        //static polymorphism
        std::cout << "Hello! I m " << static_cast<ConcreteAnimal*>(this)->getName() << end_;
    }

protected:
    std::string getName() {
        return "Animal";
    }
};


struct Dog : IAnimal<Dog> {
    std::string getName() {
        return "Dog";
    }
};

struct Cat : IAnimal<Cat> {
    std::string getName() {
        return "Cat";
    }
};

struct I2Animal : IAnimal<IAnimal<I2Animal>> {
    void sayHello() {
        std::cout << " I2Animal " << this->getName() << end_;
    }
};


int main() {

    Dog dog;
    Cat cat;

    I2Animal animal;

    animal.sayHello();

    dog.sayHello();
    cat.sayHello();

    return 0;
}

#endif // STATIC_POLY

#ifdef CRTP_LIMIT_

template<typename ToBeLimited, int maxInstance>
struct LimitNoOfInstances {

    LimitNoOfInstances()
    {
        if (count_ >= maxInstance) {
            std::cout << "Limited to " << end_;
        }

        count_.fetch_add(1); // count++
    }

    ~LimitNoOfInstances()
    {
        count_.fetch_sub(1); // count--
    }


private:
    static std::atomic<int>    count_;
}; // Copy, move & other sanity checks to be complete

template<typename A, int i>
std::atomic<int>  LimitNoOfInstances<A,i>::count_(0);

struct One : LimitNoOfInstances<One, 1> {};
struct Two : LimitNoOfInstances<Two, 2> {};

struct StringOne : LimitNoOfInstances < std::string, 2> {};

int main() {

    StringOne  string;
    StringOne  s2;
    StringOne  ss;

    std::cout << "End program" << end_;
    std::cin.get();
    return 0;
}


#endif // CRTP_LIMIT
