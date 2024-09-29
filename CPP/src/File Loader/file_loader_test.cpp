#include <include/files/opendialogfile.h>
#include <include/string/string_utility.h>
#include "file_loader.hpp"

#define  _SIZE_INT     sizeof(int)
#define  _SIZE_FLOAT   sizeof(float)
#define  _SIZE_INT64   sizeof(size_t)



int main() {

	//auto file_name =sfl::conv::wstr_to_str( opendialog::OpenFile());

	std::string file_name = R"(C:\Users\Acer\Repository\binary.bin)";

	std::fstream  file(file_name, std::ios::in | std::ios::out | std::ios::binary);

	file::Buffer<int> ibuffer;
	file::Buffer<float> fbuffer;

	file::load_file(file, fbuffer, 0, 8);
	file::load_file(file, ibuffer, 0, 8);

	// printing this buffer
	file::print_buffer(ibuffer, "buffer of integer");

	file::print_buffer(fbuffer, "buffer of flaot  ");

	// modifying the file
	file::Buffer<int> ibuf;

	ibuf.push_back(34);
	ibuf.push_back(324);
	ibuf.push_back(3444);
	ibuf.push_back(0);
	ibuf.push_back(0xffff);

	file::upload_file(file, ibuf, 0xA0, 4);

	



	return 0;
}