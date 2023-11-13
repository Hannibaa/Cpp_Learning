#include <iostream>
#include <filesystem>
#include "MyLib/Console_Library/escape_code.h"

/* 
    here we go testing directory_iterator() object 
*/

namespace fs = std::filesystem;

using vecPath = std::vector<fs::path>;

vecPath get_files_directory(const fs::path& folder_name) {

	vecPath vec_paths{};

	for (auto& p : fs::directory_iterator(folder_name)) {
		if (fs::is_regular_file(p.path())) {
			vec_paths.emplace_back(p.path());
		}
	}

	return vec_paths;
}

int main()
{
	std::string folder_name = "C:\\";

	fs::directory_iterator directory(folder_name);
	int count{}, count_fifo{}, count_dir{};
	for (auto& p : directory) {

		if (fs::is_regular_file(p.path())) {
		    print_ << "regular file : " << p.path().string() << end_;
		    ++count;
		}

		if (fs::is_fifo(p.path())) {
			print_ << "fifo : " << p.path().string() << end_;
			++count_fifo;
		}

		if (fs::is_directory(p.path())) {
			++count_dir;
		}

	}

	print_ << "number of files      : " << count      << end_;
	print_ << "number of fifo       : " << count_fifo << end_;
	print_ << "number of directory  : " << count_dir << end_;

	wait_;
	print_ << ERASESCREEN << MOVEHOME;
	auto current_dir = fs::current_path();

	auto files = get_files_directory(current_dir);
	print_ << "folder : [" << current_dir.string() << "]\n";
	count = 0;
	for (auto& f : files) {
		++count;
		print_ << "file " << count << " : [" << f.filename().string() << "]\n";
		if (count % 15 == 0) wait_;
	}

	print_ << "number of files : " << files.size() << end_;

	std::cin.get();
	return 0;
}