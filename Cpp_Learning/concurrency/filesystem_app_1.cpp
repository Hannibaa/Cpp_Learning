#include <iostream>
#include <fstream>
#include <filesystem>
#include "MyLib/opendialogfile.h"
#include "MyLib/Console_Library/escape_code.h"

namespace fs = std::filesystem;

void get_files_directory(const fs::path& directory, std::ofstream& file) {

	for (auto& p : fs::directory_iterator(directory)) {
		Print_(color::Green, "file : ") << p.path() << end_;
		
		file << p.path().string() << end_;
	}

}

int main()
{
	fs::path directory = opendialog::OpenFolder(L"Open Any Folder");

	if (directory.empty()) {
		Print_(color::Red, "No Loading...") << end_;
		return -1;
	}

	print_ << "folder : " << directory << end_;

	fs::path file;

	print_ << "select saved result in file" << end_;
	wait_;
	file = opendialog::SaveFile(L"save file", L"*.txt").first;

	print_ << "save to : " << file.string() << end_;

	wait_;
	if (file.empty()) {
		Print_(color::Red, "there no file to save result, set to default; files.txt") << end_;
		file = "files.txt";
	}

	std::ofstream ofs{ file };

	get_files_directory(directory, ofs);

	print_ << "end...\n";

	std::cin.get();
	return 0;
}