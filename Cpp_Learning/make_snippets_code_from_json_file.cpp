#include <iostream>
#include <MyLib/strings/xml_snippet.h>

// remove successive repitition of char or blank; and leave one 
std::string remove_successive_char(const std::string& text, char _char) {



	return {};
}


int main()
{
	fs::path file_name_jason = "C:\\Users\\Acer\\source\\Course C++\\Cpp_Learning\\Cpp_Learning\\glsl_snippets.json";
	fs::path file_snippet = "C:\\Users\\Acer\\source\\MyCodeSnippets\\Test1.snippet";

	auto text = Str::LoadFileToString(file_snippet);

	Print_(color::Green, "snippet file : ") << end_;
	print_ << text << end_;
	wait_;
	// clear screen.
	esc::cls();

	//remove_comment_json(text);

	/*std::string text(R"(<?xml version="1.0" encoding="utf-8" ?>
<CodeSnippets  xmlns="http://schemas.microsoft.com/VisualStudio/2005/CodeSnippet">
	<CodeSnippet Format="1.0.0">
		<Header >
			<Title>exemple for snippets</Title>
			<Shortcut>test<  / Shortcut>
			<Description>minimum code to write program</Description>
			<Author>Aoues Kadda< /  Author >
			<    SnippetTypes   >
				<SnippetType>Expansion</SnippetType>
				<SnippetType>SurroundsWith</   SnippetType>
			</SnippetTypes>
		</Header>
		<Snippet>

			<Code Language="cpp">
				<![CDATA[cout << "hello world \n";]]>
			< /    Code>
		<     /                 Snippet>
	</CodeSnippet         >
<               /CodeSnippets>)");*/


	// checking remove_char_str
	/*
	std::string str = "hello     < /.  is th er";
	print_ << str.size() << "|" << str << end_;
	str = remove_char(str, 10,  14, ' ');
	print_ << str.size() << "|" << str << end_;
	return 89;                                      */



	// trait of code and remove any space from tags; // not good
	xml::trait_xml_string_removeblanks(text);
	Print_(color::Green, "code after traitement") << end_;
	print_ << text << end_;

	return 1;

	// get all xml element and print it;
	auto vec = xml::get_all_xml_tags(text);
	print_ << "size vec : " << vec.size() << end_;
	int k{};
	for (auto& s : vec) {
	    print_ << "tag n " << ++k << " : [" << s << "] ";
		bool attr = xml::is_xml_tag_has_attribute(s);
		print_ << "has attribute : " << "FT"[attr] ;
		Print_(color::Green, " number of attributes : ") << 
			COLOR(color::Red, xml::number_attribute_in_xml_tag(s));
		if (attr) xml::print_snippet_attr( xml::get_attribute_tag(s) ) ;
		print_ << end_;
	}

	// check element who have attributes:



	std::cin.get();
	return 0;
}