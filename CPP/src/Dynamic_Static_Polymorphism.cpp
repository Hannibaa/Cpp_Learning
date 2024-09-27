#include <iostream>


#define  print_    std::cout

// Dynamic -----------------------------------------------
class Base {
public:
	virtual void Impl() {
		print_ << "Base Impl\n";
	}

	virtual ~Base() = default;
};

// derived 
class D1 : public Base {
public:
	void Impl() override {
		print_ << "D1 override methode \n";
	}
};

// derived 
class D2 : public Base {
public:
	void Impl() override {
		print_ << "D2 override methode\n";
	}
};


// static -----------------------------------------------

template<class Drived>
struct sBase {
	void Interface() {
		print_ << "Call Interface\n";
		static_cast<Drived*>(this)->Impl();
	}

protected:
	void Impl() {
		print_ << "Base Implementation\n";
	}
};

struct Derive1 : sBase<Derive1> {
	// using base implementation
};

struct Derive2 : sBase<Derive2> {

	void Impl() {
		print_ << "Derive2 Implementation\n";
	}
};





// Static Poly
int main2() {

	Derive1 d1;
	Derive2 d2;

	d1.Interface();
	d2.Interface();



	return 0;
}




// Dynamic Poly
int main1() {

	Base b;
	D1 d1;
	D2 d2;

	b.Impl();
	d1.Impl();
	d2.Impl();

	static_cast<Base>(d1).Impl();
	dynamic_cast<Base&>(d2).Impl();


	return 0;
}