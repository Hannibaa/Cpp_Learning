/*
                                THIS PROGRAMME USE ALL POWER OF C++ 
                                1. Load Dictionary in momory
                                1.1 Loading from file in 
                                1.2 Using our CFile classes helper
                                2. Create Random Words or text to check it word by word
                                3. Affich result in screen.
                                4. analysis.

*/

#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include <fstream>
#include <filesystem>
#include <MyLib/vector_utility1.h>
#include <MyLib/random_vector.h>


namespace fs = std::filesystem;


/// this function just put or read container from or to file that you are designed to;
// need additional option for if you need to change vector that in file.

template<typename Container>
Container get_vector_inout_file(const fs::path& filename, const Container& C = {}, bool new_value = false) {

#ifndef end_
#define end_ '\n'
#endif

    // If you want to force to put new value in file and lose old value;
    if (new_value) goto New_Value;

    // If file exist extract vector form it and returned 
    if ( fs::exists(filename) ) {
        std::cout << "file [" << filename.string() << "] Size ["<< fs::file_size(filename) << "]" << end_;

        // open file for reading
        std::ifstream ifs{ filename };

        // check file if is open correctly
        if (!ifs.is_open()) {
            std::cout << "file in not open correctly\n";
            return Container{};
        }

        // start get number from file 
        Container tempC{};
        typename Container::value_type value{};

        while (ifs >> value) {
            tempC.push_back(value);
        }

        ifs.close();

        return tempC;
    }

New_Value:
    // If not exist than create file and write Container in file
    // Container should not be empty
    if (C.empty()) {
        std::cout << "The container is empty\n";
        return Container{};
    }

    std::ofstream ofs{ filename };

    if (!ofs.is_open()) {
        std::cout << "Error of opening file " << end_;
        return Container{};
    }

    for (auto& element : C) {
        ofs << element << " ";
    }

    std::cout << "all element copy to file " << filename.string() << end_;
    ofs.close();

    return C;
}




int main()
{
    fs::path filename = "myvector.txt";

    auto container = vu::makeRandomContainer<std::vector, int>(-100, 100, 20);

    vu::print_container(container, 10);

   auto vec_from_file = get_vector_inout_file(filename, container);

   newline_;

   print_ << ESC::Colors::_MAGENTA_FG << "get vector from file : " << ESC::Colors::_RESETMODE << end_;

   vu::print_container(vec_from_file, 10);

   print_ << COLOR(color::Green, "vector get it from random function") << end_;

   vu::print_container(container);

   // I like to put this new vector in same file and replace all value;
   get_vector_inout_file(filename, container, true);

   // extract of this vector
   vec_from_file = get_vector_inout_file<std::vector<int>>(filename);

   // print it out in screen
   print_ << COLOR(color::Red, "print new value from file ") << end_;

   vu::print_container(vec_from_file);

    wait_;
    return 0;
}