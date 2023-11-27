#include <iostream>
#include <MyLib/Snippet_make.h>
#include "MyLib/Console_Library/escape_code.h"


int main()
{
	fs::path json_file = R"(C:\Users\Acer\source\Course C++\Cpp_Learning\Cpp_Learning\glsl_snippets.json)";
	fs::path dir = R"(C:\Users\Acer\Documents\woman)";

	Snippet::generate_snippet_files_from_json(json_file, dir);


	std::cin.get();
	return 0;
}