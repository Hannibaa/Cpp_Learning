#include <iostream>
#include <memory>
#include "life_time.h"
//#include <.../.../MyLib/Console_Library/escape_code.h>

#define end_    '\n'
#define line_   std::cout << "---------------------------------------------------------------------\n"
#define wait_   std::cin.get()
#define print_  std::cout 

using namespace std;

Lifetime CreateDefault(){
	return Lifetime();
}

Lifetime CreateLifetime(float v) {
	return Lifetime(v);
}

Lifetime* CreatePointerDefault() {
	Lifetime* t = new Lifetime();
	return t;
}

auto CreateUnique() {
	return std::make_unique<Lifetime>();
}

int main()
{
	auto t1 = CreateDefault();
	auto t2 = CreateLifetime(4.5f);
	auto ptr_t =std::unique_ptr<Lifetime>( CreatePointerDefault());
	auto uniq = std::make_unique<Lifetime>();
	uniq->value_() = 40.55f;

	print_ << " t1 " << t1.value_() << end_;
	print_ << " t2 " << t2.Value()  << end_;
	print_ << " ptr " << ptr_t->getValue() << end_;
	print_ << " uniq " << uniq->getValue() << end_;

	cin.get();
	return 0;
}