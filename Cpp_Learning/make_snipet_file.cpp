#include <iostream>
#include <MyLib/strings/xml_snippet.h>

/*
         this exemple of demostration how to use new library xml_snippet.h
		 loading file and using xml_snippet functions
*/


int main()
{
	
	fs::path file_name_jason = "C:\\Users\\Acer\\source\\Course C++\\Cpp_Learning\\Cpp_Learning\\glsl_snippets.json";
	fs::path file_snippet   = "C:\\Users\\Acer\\source\\MyCodeSnippets\\Test1.snippet";
	fs::path file_saved1      = File::name_same_path_extension(file_snippet,"snip_1");
	fs::path file_saved2      = File::name_same_path_extension(file_snippet,"snip_2");

	auto text = File::loadFileToString(file_snippet);

	Print_(color::Green, "snippet file : ") << end_;
	print_ << text << end_;
	wait_;

	esc::cls();
	//print_ << "tag : [" << xml::code::Description << "|" << xml::code::eDescription << end_;
	print_ << "Description :" << end_;
	print_ << "["<< xml::get_xml_string_value(text, xml::element::Description) << "]\n";

	xml::set_xml_string_value(text, xml::element::Title, " line exemples file 1");
	xml::set_xml_string_value(text, xml::element::Description, "Draw line in termimal");
	xml::set_xml_string_value(text, xml::element::Shortcut, "line");
	xml::set_xml_string_value(text, xml::element::Body, "std::cout << \"--------\";");

	auto tx = xml::make_quicksnippet_code("line exemples file 2 with quick snippet ", 
		"draw line in terminal",
		"line", "std::cout << \"--------\";");

	Print_(color::Red, "text after modification :") << end_;
	print_ << text << end_;

	File::saveStringToFile(text, file_saved1);
	Print_(color::Green, "saved to file : ") << file_saved1.string() << end_;
	File::saveStringToFile(tx, file_saved2);
	Print_(color::Green, "saved to file : ") << file_saved2.string() << end_;
	// clear screen.

	Print_(color::Red, "End of program....thank you.") << end_;

	std::cin.get();
	return 0;
}










/*std::string text0 = "hello this one i n 123132";
	std::string text2 = " hello   this one i n 123132";
	std::string text3 = "     hello         this one i n 123132     ";
	std::string text4 = " hello this      one i n     123132 ";

	print_ << text0 << end_ << "after : [" << Str::remove_successive_char(text0) << "]\n";
	print_ << text2 << end_ << "after : [" << Str::remove_successive_char(text2) << "]\n";
	print_ << text3 << end_ << "after : [" << Str::remove_successive_char(text3) << "]\n";
	print_ << text4 << end_ << "after : [" << Str::remove_successive_char(text4) << "]\n";

	return 0;*/
