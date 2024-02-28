#include <iostream>
#include <vector>

#include <MyLib/random_generator.h>

/*
         in this exemple we creating 100 particule class 
		 and check it if these particule contain in box of some dimension
		 after we going to erase these particules from vector<particule>
*/

#define end_   '\n'
#define wait_   std::cin.get()

struct Stat {

};

struct Particule {

	Stat&    m_stat;

	int     _id;
	float     x;
	float     y;

	Particule(Stat& __stat, float _x , float _y , int id = 0 ) 
		:m_stat{ __stat }, 
		_id { id}, x{ _x }, y{ _y }
	{}

};

template<typename P>
void create_100_particules(std::vector<P>&  vec, Stat& __stat) {
	vec.reserve(110);
	rng::fRG<float> frand;
	for (int i = 0; i < 100; ++i)
	{
		vec.push_back(P{__stat, frand(0.f,100.f), frand(0.f,100.f) , i });
	}
}

template<typename V>
void print_vector(const V& v, int k) {

	for (const auto& e : v) {
		std::cout << "[ " << e._id << " | " << e.x << " , " << e.y << "]\n";
		if (!--k) break;
	}

}

template<typename T>
struct Box {
	T x;
	T y;
	T w;
	T h;

	bool contain(T a, T b) const {
		return  a >= x && a <= x + w && b >= y && b <= y + h;
	}
};

int numbers_particule_in_box(std::vector<Particule>& vecp, Box<float>& box) {
	int count{};
	for (const auto& p : vecp) {
		if (box.contain(p.x, p.y)) ++count;
	}

	return count;
}


int main() {
	Stat  stat;
	std::vector<Particule> vec;

	create_100_particules(vec, stat);

	std::cout << "capacity of vector : " << vec.capacity() << end_;
	std::cout << "size of vector : " << vec.size() << end_;

	print_vector(vec, 15);

	// etablish logic to delete some value that that particule contain in some region in 0 and 100
	// for exemple box(x,y,w,h)

	Box<float> box{.x = 0.f, .y = 0.f, .w = 100.f, .h = 10.f};


	int times_0{};
	while (numbers_particule_in_box(vec, box) == 0) {
		++times_0;
		vec.clear();
		create_100_particules(vec,stat);
		std::cout << "times : " << times_0 << end_;
		std::cin.get();
	}

	std::cout << "number of times get 0 : " << times_0 << end_;
	std::cout << "number of point in box is " << numbers_particule_in_box(vec, box) << end_;

	// we goint to remove this point :
	wait_;
	for (auto it = vec.begin(); it != vec.end(); ) {
		if (box.contain(it->x, it->y)) {
			std::cout << "point id : " << it->_id << end_;
			it = vec.erase(it);
			// it return iterator after
			std::cout << "point id : " << it->_id << end_;
		}
		else ++it;
	}

	std::cout << "new size of vector is : " << vec.size() << end_;


	std::cout << "End of program...\n";
	std::cin.get();
	return 0;
}