#include <iostream>
#include <MyLib/strings/xml_snippet.h>

/*
		 this exemple of demostration how to use new library xml_snippet.h
		 generate files snippets from json file
*/



int main()
{
	fs::path snippet = "C:\\Users\\Acer\\source\\MyCodeSnippets\\snippet_files";
	fs::path file_json = "C:\\Users\\Acer\\source\\Course C++\\Cpp_Learning\\Cpp_Learning\\glsl_snippets.json";

	

	if (!fs::exists(snippet)) {
		Print_(color::Red, "Folder missed!...") << end_;
		return -2;
	}

	if (!fs::exists(file_json)) {
		Print_(color::Red, "File json missed!...") << end_;

	}

	xml::generate_snippet_files_from_json(file_json, snippet);
	


	std::cin.get();
	return 0;
}