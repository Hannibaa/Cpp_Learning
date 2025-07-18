#include <iostream>

#define end_ '\n'
void move(void* _ptr, float& f);




class func {

public: 

	float half_float(float v) {
		std::cout << "set float function called " << end_;
		return v / 2.f;
	}

	float double_float(float v) {
		std::cout << "double float : \n";
		return 2.f * v;
	}
};



template<typename T>
void check(T* ptr, float& v) {
	move(ptr, v);
}



int main() {


	func f;
	float x = 10.f;

	move(&f, x);

	std::cout << " x " << x << end_;

	check(&f, x);

	std::cout << " x " << x << end_;

	std::cin.get();
	return 0;
}





void move(void* _ptr, float& f) {

	
	static_cast<func*>(_ptr)->double_float(f);

}