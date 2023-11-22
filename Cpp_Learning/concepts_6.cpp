#include <concepts>
#include <string>
#include <vector>

using namespace std::string_literals;

template<std::convertible_to<std::string>  Text>
struct SomeOtherType {};

template<typename T>
struct AnyType {};

template<typename T>
concept TypeRequirements = requires {
	// type requirement, T::value must name a type
	//typename T::value_type;
	// type requirements can be template instantiations
	typename SomeOtherType<T>;
	//typename AnyType<T>;
	// In this case, SomeOtherType<T> is only valid 
	// if T is convertible to std::string
};

template<typename T>
concept SimpleAndCompound = requires(T a, T b) { // optional section
	// for creating named arguments

	a + b; // simple requirement, exxpression a + b has to be valid
	{a + b}; // compound version of the same
	{a + b} noexcept; // expression valid and does not throw
	{a + b} -> std::same_as<T>; // expression valid and returns T
};

template<typename T>
concept Nested = requires {
	// simplest nested requirement, always satisfied
		requires true;
    // nested requirement
    // std::convertible_to<T,int> must evaluate to true
    requires std::convertible_to<T,int>;
    
    // Note the difference from :
    std::convertible_to<T, int>;  // simple requirement 
	// std::convertible_to<T,int> has to be
	// a valid expression (ignore the result)
};

template<typename String>
requires TypeRequirements<String>
void get(String str);


int main() {

	std::vector<char> vechar;

	get("hello"s);
	get(3344);
	get("hello");
	get(vechar);

	return 0;
}