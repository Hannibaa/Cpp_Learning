/* this code inspired from cherno channel exemple */

#include <iostream>
#include <fstream>
#include <thread>
#include <future>
#include <filesystem>
#include "MyLib/Console_Library/escape_code.h"

// todo will complete with async
namespace fs = std::filesystem;

std::string loadfile(const std::string& file) {

	std::ifstream ifs{ file };

	if (!ifs.is_open()) {
		Print_(color::Red, "Error...") << end_;
		return {};
	}
	std::string result;
	std::string str;
	// need mutex???
	while (std::getline(ifs, str)) {
		result += str;
	}

	ifs.close();
	print_ << "thread Id : " << std::this_thread::get_id() << end_;
	return result;
}

std::vector<std::string> get_files(const std::string& file) {

	std::ifstream ifs{ file };
	std::vector<std::string> vf;

	if (!ifs.is_open()) {
		Print_(color::Red, "Error...") << end_;
		return {};
	}

	std::string f;

	while (std::getline(ifs, f)) {
		vf.push_back(f);
	}

	ifs.close();
	return vf;
}

int main()
{
	std::string files = R"(C:\Users\Acer\source\Course C++\Cpp_Learning\Cpp_Learning\concurrency\files.txt)";

	auto vfiles = get_files(files);


	int i{};
	for (const auto& f : vfiles) print_ << ++i << "/ [ " << f << end_;

	print_ << "press enter to continue...";
	wait_;
	esc::cls();
	print_ << "loading files : \n";

	// load first file
	auto tp = std::chrono::steady_clock::now();

	std::vector<std::future<std::string>> vf_str;

	for (const auto& file : vfiles) {
		//auto str = loadfile(file);
		vf_str.push_back(std::async(std::launch::async, loadfile, file));
		fs::path _path = file;
		Print_(color::Fuchsia, "size of : ") << _path.filename().string() << end_;
		//	<< "  " << vf_str[vf_str.size() - 1].get().size() << end_;
	}

	for (const auto& str : vf_str) {
		Print_(color::Green, "Size of : ") << str._Get_value().size() << end_;
	}

	std::chrono::duration<float>  duration = std::chrono::steady_clock::now() - tp;

	Print_(color::Green, "time of loading of these files is : ") << duration << end_;

	std::cin.get();
	return 0;
}