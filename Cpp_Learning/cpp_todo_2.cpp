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
	print_ << "number of files is    : " << files.size() << end_;
	wait_;
	// we read all todo comment from files in current directory.
	// files should be *.cpp, *.h, *.hpp, *.c;
	// loop on files
	int count{};
	cpp::vecComments todo_list;

	for (const auto& f : files) {
		// check if is it C++ files
		auto extension = f.extension().string();
		if (extension == ".cpp" || extension == ".h"
			|| extension == ".hpp" || extension == ".c")
		{
			print_ << "cpp file : " << f.string() << end_;
			++count;
			auto todo_ = cpp::read_todo_comment(f);
			todo_list.insert(todo_list.end(), todo_.begin(), todo_.end());
		}
	}
	
	print_ << "there are : " << count << end_;

	//auto todo_list = cpp::read_todo_comment(files[2]);

	cpp::print_comments(todo_list, "todo list of file :\n" + files[2].string());


	std::cin.get();
	return 0;
}