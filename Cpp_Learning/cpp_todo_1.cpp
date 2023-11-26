#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/strings/cpp_fles.h"

/*
       Testing cpp_files comments.
*/



int main()
{
	fs::path current = fs::current_path();

	Print_(color::Green, "Current directory is : ") << COLOR(color::Red, current.string()) << end_;

	// get files and directory in this 

	auto files = File::get_files_directory(current);
	auto directories = File::get_Any_directory(current, fs::is_directory);

	print_ << "number of directories : " << directories.size() << end_;
	print_ << "number of files is    : " << files.size() << end_;

	auto todo_list = cpp::read_comment_cpp(files[2]);
	
	cpp::print_comments(todo_list, "comment of file :\n" + files[2].string());

	wait_;
	
	// geting to do list of this file

	todo_list.clear();
	todo_list = cpp::read_todo_comment(files[2]);

	cpp::print_comments(todo_list, "todo list of file :\n" + files[2].string());


	std::cin.get();
	return 0;
}