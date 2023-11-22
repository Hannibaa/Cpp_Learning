#include <iostream>
#include <MyLib/strings/xml_snippet.h>

/*
		 this exemple of demostration how to use new library xml_snippet.h
		 loading file and using json functions
*/



int main()
{
	fs::path file_name_json = "C:\\Users\\Acer\\source\\Course C++\\Cpp_Learning\\Cpp_Learning\\glsl_snippets.json";
	fs::path file_snippet = "C:\\Users\\Acer\\source\\MyCodeSnippets\\Test1.snippet";
	fs::path file_saved1 = File::name_same_path_extension(file_snippet, "snip_1");
	fs::path file_saved2 = File::name_same_path_extension(file_snippet, "snip_2");

	std::string body0(R"("for(int $2 = 0; $2 < $3; $2++){",
                	  "\t",
                       "}")");

	std::string body("continue;");

     print_ << "body before process : " << end_;
     print_ <<"[" << body << "]" << end_; 
	 wait_;

     body = xml::snippet_process_body_(body);
     print_ << "body after process : " << end_;
     print_ << "[" << body << "]" << end_;




	return 10;

	auto text = File::loadFileToString(file_name_json);

	auto vSinfo = xml::json_get_SnippetInfo(text);

	print_ << "number of operation " << vSinfo.size() << end_;


	std::cin.get();
	return 0;
}


//std::string text = R"("for": {
//	"prefix": "for",
//	"body": [
//	  "for(int $2 = 0; $2 < $3; $2++){",
//	  "\t",
//	  "}"
//	],
//	"description": "for( ; ; ){\n\t//code\n}\n\nThe keyword for is used to describe a loop that is controlled by a counter. The parentheses enclose three expressions that initialize, check and update the variable used as counter. The body defined by curly braces encloses the statements that are executed at each pass of the loop.\n\nfor(int i = 0; i <= 99; i++){\n\taFunction();\n}\n\nThe execution of a single pass or the whole loop can be aborted by using a continue or a break statement respectively."
//  )";







//size_t pos{};
//print_ << "first string ; [" << Str::get_quoted(text, pos) << "]\n";
//++pos;
//print_ << "first string ; [" << Str::get_quoted(text, pos) << "]\n";

//auto si = xml::json_process_string(text);
//Print_(color::Red, "print info : ") << end_;
//xml::print_snippetInfo(si);

//print_ << "body before process : " << end_;
//print_ <<"[" << si._body << "]" << end_; wait_;
//si._body = xml::snippet_process_body_(si._body);
//print_ << "body after process : " << end_;
//print_ << "[" << si._body << "]" << end_;
