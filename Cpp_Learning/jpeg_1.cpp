#define   JCONFIG_INCLUDED
extern "C" {
#include <include/bitmap/jpeg-6b/jpeglib.h>
}

#include <iostream>
#include <cstdio>
#include <include/files/opendialogfile.h>


int main() {
	// Exemple fo usage of libjpeg in C++ 

	std::wstring file_name;

	file_name = opendialog::OpenFile(L"Chose JPEG file",  {L"JPEG ONLY", L"*.jpeg"});

	std::wcout << "File Jpeg : " << file_name << '\n';

	return 0;
}


