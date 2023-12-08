#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/static_vector.h"
#include "MyLib/container_utility.h"

template<typename Vector>
void get_info_vector(const Vector& vec, const std::string_view comment = "") {

	Print_(color::Green, "--------------------------------------------") << end_;
	Print_(color::Fuchsia, comment) << end_;
	Print_(color::Green, "--------------------------------------------") << end_;

	Print_(color::Green, "capacity : ") << vec.capacity() << end_;
	Print_(color::Green, "size     : ") << vec.size() << end_;
	Print_(color::Green, "max size : ") << vec.max_size() << end_;
	Print_(color::Green, "value type : ") << typeid(typename Vector::value_type).name() << end_;
	Print_(color::Green, "--------------------------------------------") << end_;

}

#define ncr_(n)        std::cout << std::string(n,'\n').c_str();

int main()
{
	static_vector<float, 10>  v1;

	cu::print_container(v1, "static vector elements : ");


	v1.push_back(33.3f);
	print_ << "first push back : " << v1.size() << end_;

	// we try to fill up using push back method
	for (int i = 0; i < 15; ++i) {
		v1.push_back(float(i));
	}

	cu::print_container(v1, "static vector elements afer fill : ");

	// trying to add value in midle of vector :

	v1.insert(v1.begin() + 3, 3.55f);

	cu::print_container(v1, "static vector elements afer insert  : ");


	// erase 3 elements

	v1.erase(v1.begin() + 3, v1.end() - 2);

	cu::print_container(v1, "static vector elements after erase");

	v1.insert(v1.begin() + 2, 1000.f);

	v1.insert(v1.end(), 2000.f);

	cu::print_container(v1, "static vector elements after insert 1000");

	// using insert value from other continair
	float a[10];
	v1.insert(v1.begin() + 1, a + 2, a + 8);

	cu::print_container(v1, "static vector element after insert sequences");

	ncr_(2);
	get_info_vector(v1, "info about vector : ");
	print_ << "End......" << end_;
	std::cin.get();
	return 0;
}