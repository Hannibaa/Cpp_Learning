#include <iostream>
#include <string>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"
#include <MyLib/stringfunctionhelper.h>

/*  
     THIS SMALL PROGRAMME DEMONSTRAT THE USE OF 
	 1. RAW LITERALS STRING
	 2. PUTS (puts(char *) FUNCTION 
	 3. USE SOME ESCAPES CHARACTER 
*/


using namespace std;

void animated_text(const std::string& text) {
	auto v_words = Str::putTextInVectorWords(text);


}

// define function to clean screen 
void clear() {
	std::cout << ERASESCREEN;
}


int main()
{
	puts(R"(1/) hello/ this /n morning 33##$$%\n "--cotation--" 
            2/) here we can put any things -><-)");

	string Rstring = R"( this one will take two line 
                        and this second line  )";
	newline_;
	Print_(color::Green, Rstring) << end_;
	Print_(color::Red, Rstring.length()) << Rstring.size() << end_;
	wait_;
	std::this_thread::sleep_for(20s);
	clear();
	puts(GREEN_BG);
	print_ << MOVETO(0,0);
	puts("hello");
	puts(RESETMODE);
	cin.get();
	return 0;
}