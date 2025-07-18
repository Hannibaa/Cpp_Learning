#include <iostream>
#include <map>


#define  end_ '\n'

using std::cout;
using std::cin;

//struct sButton
//{
//	int& mouse;
//	std::string  name;
//
//	sButton(int& m, const std::string& _name)
//		:mouse(m)
//		,name(_name)
//	{}
//
//	sButton& operator = (const sButton& other) {
//		mouse = other.mouse;
//		name = other.name;
//
//		return *this;
//	}
//};

struct sButton
{
	int* mouse;
	std::string  name;

	sButton()
		:mouse(nullptr)
		,name()
	{}

	sButton(int* m, const std::string& _name)
		:mouse(m)
		,name(_name)
	{}

	sButton& operator = (const sButton& other) {
		mouse = other.mouse;
		name = other.name;

		return *this;
	}
};



int main() {
	int mouse{};
	std::map<std::string, sButton>  mapButton;

	mapButton["click"] = sButton( &mouse, "hello" ); //this not working for reference member

	//mapButton.insert({ "click",sButton(&mouse, "hello") });


	if (mapButton["click"].name == "hello") cout << "is ok" << end_;


	cin.get();
	return 0;
}

/*								 CONCLUSION 
								------------


--------------- NEVER AND EVER NEVER USE REFERENCE AS MEMBER IN CLASS ---------------------------
--------------- NEVER AND EVER NEVER USE REFERENCE AS MEMBER IN CLASS ---------------------------
--------------- NEVER AND EVER NEVER USE REFERENCE AS MEMBER IN CLASS ---------------------------
--------------- NEVER AND EVER NEVER USE REFERENCE AS MEMBER IN CLASS ---------------------------
--------------- NEVER AND EVER NEVER USE REFERENCE AS MEMBER IN CLASS ---------------------------
--------------- NEVER AND EVER NEVER USE REFERENCE AS MEMBER IN CLASS ---------------------------
--------------- NEVER AND EVER NEVER USE REFERENCE AS MEMBER IN CLASS ---------------------------

*/