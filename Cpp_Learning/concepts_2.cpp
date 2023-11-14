#include <iostream>
#include <string>
#include <MyLib/containers.h>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include "mylib/Headers/my_concepts.h"


template<typename ...Args>
constexpr std::enable_if_t<Concept::are_same_v<Args...>, Concept::first_arg_t<Args...>>
Add(Args&&...args) noexcept
{
	return (... + args);
}

template<typename...Args>
requires Concept::Addable<Args...>
Concept::first_arg_t<Args...> Add_(Args&&...args) noexcept
{
	return (... + args);
}




int main()
{
	print_ << "add 1 + 2 + 3 = " << Add(1, 2, 3) << end_;
	//print_ << "Add mixt number 1 + 2.0f...." << Add(1, 2.0f, 3.0f) << end_;
	auto x = Add_(3.f, 2.5f, 1.4f);
	print_ << "add_ version 2 " << Add_(1.0, 2.0, 5.3) << end_;
	print_ << "x " << x << end_;

	print_ << "add one number " << Add(5.7) << end_;

	std::cin.get();
	return 0;
}