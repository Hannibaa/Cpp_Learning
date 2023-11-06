#include <iostream>
#include <Mylib/Console_Library/escape_code.h>
#include <MyLib/stringfunctionhelper.h>


using namespace std::string_literals;
/*
	author : KADDA Aoues
	example of bit field and template<> and structure
	we name this file version 2;
	Using Macro to define a new type

*/


#define   Field(Part_of)        template<typename T, size_t N>             \
	requires (8 * sizeof(T) > N) && std::is_trivially_copyable_v<T>        \
struct  Part_of {                                                          \
private:                                                                   \
	T Lpart : N;                                                           \                  
	T Upart : 8 * sizeof(T) - N;                                           \    
		                                                                   \
public:                                                                    \
		Part_of(const T& _t = T{}) {                                       \
		*this = std::bit_cast<Part_of>(_t);                                \
	}                                                                      \
		                                                                   \
	operator T() {                                                         \
		return Lpart;                                                      \
	}                                                                      \
		                                                                   \
	T operator[](size_t part) {                                            \
		if (part == 0) return Lpart;                                       \
		if (part == 1) return Upart;                                       \
			                                                               \
		return std::bit_cast<T>(*this);                                    \
	}                                                                      \
		                                                                   \
	T operator[](const std::string& _str) {                                \
		\ // convert all character to lower case 
		auto str = Str::str_tolower(_str);                                 \
		\  // will check if word upper or lower is presente in string 
		if (str.find("lower") != std::string::npos) return Lpart;          \
		if (str.find("upper") != std::string::npos) return Upart;          \
		if (str.find("whole") != std::string::npos ||                      \
			str.find("all") != std::string::npos ||                        \
			str.find("number") != std::string::npos)                       \
			return std::bit_cast<T>(*this);                                \
	}                                                                      \
			                                                               \
			                                                               \
}                                                                          \


#define TYPE(name, Type, N)    struct  name {                              \
                         Type i : N;                                       \
                         Type ci : 8*sizeof(Type) - N;                     \
                         name(const Type& _t) {                   \
                             return std::bit_cast<name>(_t);               \
		                 }                                                 \
                         operator Type () {                                \
                         return i;                                         \
                         }                                                 \
}                                                                          \


TYPE(i2,unsigned int, 2) ;
TYPE(i1,unsigned int, 1) ;

i2 iii{ 0b1111'1110 }; 
i1 ii{0b0101};

template<size_t N>
struct Int {
	unsigned int i : N;              // int 0 -> N - 1     if N = 7
	unsigned int ci : 32 - N;        // int N -> 31        32 - 7 = 25

	Int(unsigned int _i = 0U) {
		*this = std::bit_cast<Int>(_i);
	}

	operator unsigned int() const {
		return i;
	}

	unsigned int compliment() const {
		return ci;
	}

	unsigned int whole() const {
		return std::bit_cast<unsigned int>(*this);
	}
};


template<typename T, size_t N>  
requires (8*sizeof(T) > N) && std::is_trivially_copyable_v<T>
struct Part_of {
private:
	T Lpart : N;                    // Lower part 0 --> N - 1;
	T Upart : 8 * sizeof(T) - N;    // Upper part N --> 8 * sizeof(T) - 1;

public:
	Part_of(const T& _t = T{}) {
		*this = std::bit_cast<Part_of>(_t);
	}

	operator T() {
		return Lpart;
	}

	T operator[](size_t part) {
		if (part == 0) return Lpart;
		if (part == 1) return Upart;

		return std::bit_cast<T>(*this);
	}

	T operator[](const std::string& _str) {
		// convert all character to lower case
		auto str = Str::str_tolower(_str);
		// will check if word upper or lower is presente in string 
		if (str.find("lower") != std::string::npos) return Lpart;
		if (str.find("upper") != std::string::npos) return Upart;
		if (str.find("whole") != std::string::npos ||
			str.find("all") != std::string::npos ||
			str.find("number") != std::string::npos)
			return std::bit_cast<T>(*this);
	}


};



int main() {

	Part_of<unsigned int, 16> i{ 0x12'34'56'78 };
	0x12'34; 0x56'78; // 4660 , 22136

	Print_(color::Green, "Checking bit field new structure") << end_;

	print_ << "conversion operator " << i << end_;
	print_ << "value lower part    " << i[0] << end_;
	print_ << "value compliment is " << i[1] << end_;
	print_ << "value all number is " << i[2] << end_;

	print_ << "value lower part    " << i[ "give me lower"s] << end_;
	print_ << "value compliment is " << i[ "upper"s] << end_;
	print_ << "value all number is " << i[ "whole"s] << end_;

	newline_; newline_;

	print_ << "value of ii and iii " << ii << " " << iii << end_;


	std::cin.get();
	return 0;
}