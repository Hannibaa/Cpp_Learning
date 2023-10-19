#include <iostream>
#include "MyLib/Console_Library/escape_code.h"


using namespace std;

#define STR_L(X)   #X
#define STR_(X)    #X#X
#define STR_2(x,y) #x#y
#define STR2(x,y)  x##y
#define STR22(x)   x##x
#define VALUE(X)   X

int main()
{
	Print_(color::Maroon, "++++++ USING SHARP SIMBOL IN PREPROCESSOR +++++++") << end_;

	int y = 345;

	const char* text = "here we are"" and there";

	STR2(int, *) z;

	/*for (int i = 0; i < 10; ++i)
	   static int STR2(var, i) {};*/

	int STR2(var, 0) = 100;
	int STR2(var, 1) = 200;
	int STR2(var, 2) = 300;

	print_ << var0 << " " << var1 << " " << var2 << end_;

	puts(STR_L(23424));
	puts(STR_L(HELLO));

	puts(STR_L(STR_L(234)));
	puts(STR_(y));
	
	puts(STR_(HELLO WORLD));

	puts(STR_2(HELLO, WORLD));
	puts(STR_2(THIS, ));
	cin.get();
	return 0;
}