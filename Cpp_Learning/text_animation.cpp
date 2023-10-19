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

void animated_text(const std::string& text,const std::chrono::seconds elapsed_time ) {
	auto v_words = Str::putTextInVectorWords(text);
	print_ << "the size of vector of words is : " << v_words.size() << end_;
	for (auto& w : v_words) {
		print_ << ERASELINE;
		move_to(40, 19);
		print_ << w;
		std::this_thread::sleep_for(elapsed_time);
	}

}

// define function to clean screen 
void clear() {
	std::cout << ERASESCREEN;
}


int main()
{
	//puts(YELLOW_BG);
	puts(RED_FG);
	move_to(0, 0);
	puts(R"(******* THIS SMALL PROG EDITED BY KADDA.A ********)");
	std::this_thread::sleep_for(4s);
	restor_mode();
	clear();
	std::string text = "Covering space - Wikipedia, the free encyclopedia fichiers";
	std::string text2 = R"(	Antisymmetric - Wikipedia, the free encyclopedia_fichiers
Clifford algebra - Wikipedia, the free encyclopedia_fichiers
Covering space - Wikipedia, the free encyclopedia_fichiers
Diffeomorphism - Wikipedia, the free encyclopedia_fichiers
Differentiable manifold - Wikipedia, the free encyclopedia_fichiers
General linear group - Wikipedia, the free encyclopedia_fichiers
Group representation - Wikipedia, the free encyclopedia_fichiers
Inversive ring geometry - Wikipedia, the free encyclopedia_fichiers
Killing form - Wikipedia, the free encyclopedia_fichiers
Lie group - Wikipedia, the free encyclopedia_fichiers
Möbius transformation - Wikipedia, the free encyclopedia_fichiers
Orthogonal group - Wikipedia, the free encyclopedia_fichiers
Pin group - Wikipedia, the free encyclopedia_fichiers
Poincaré half - plane model - Wikipedia, the free encyclopedia_fichiers
Representation theory of SL2(R) - Wikipedia, the free encyclopedia_fichiers
Rotation(mathematics) - Wikipedia, the free encyclopedia_fichiers
SL2(R) - Wikipedia, the free encyclopedia_fichiers
Spinor - Wikipedia, the free encyclopedia_fichiers)";


	animated_text(text2, 1s);


	cin.get();
	return 0;
}