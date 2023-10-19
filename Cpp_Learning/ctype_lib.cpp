/* 
                 TEST CTYPE LIBRARY ctype.h FUNCTIONS
                 ONE BY ONE
                 WILL CHECK ALL CHARACTER 
*/

#include <iostream>
#include <cctype>
#include <algorithm>
#include <MyLib/opendialogfile.h>
#include <MyLib/Console_Library/escape_code.h>
#include <MyLib/stringfunctionhelper.h>


int count_alphabet(const std::string_view str) {

    return std::count_if(str.begin(), str.end(), [](unsigned char c) {return std::isalpha(c); });

}

int count_space(const std::string_view str) {

    return std::count_if(str.begin(), str.end(), [](unsigned char c) {return std::isspace(c); });

}

template<typename Fn>
int count_function(const std::string_view str, Fn BoolFuncChar) {

    return std::count_if(str.begin(), str.end(), BoolFuncChar);

}

template<typename IsComp>
int count_func(const std::string_view str, IsComp is_func) {

    return std::count_if(str.begin(), str.end(), [](unsigned char c) { return is_func(c); });

}



int main()
{
    Print_(color::Green, "Test all function in library cctype and ctype, and their failure ") << end_;

    std::string text = "this one of there are not here 123434\n";

    std::string text2 = Str::LoadFileToString("Text.txt");

    // if you like to chose any file in disk
    Print_(color::Red, "chose any file in disk y/n") << end_;
    char yn{};
    std::cin >> yn;

    if (yn == 'y' || yn == 'Y') {
        // get file from disk;
        auto filename = opendialog::OpenFile(L"Get file that will put it in String");
        wprint_ << L"file name is : " << filename << end_;
        text2.clear();
        text2 = Str::LoadFileToString(filename);
    }

    print_ << "text2 is \n" << text2 << end_;

    print_ << "count the alphabet " << count_alphabet(text2) << end_;
    print_ << "count the space    " << count_space(text2) << end_;
    //print_ << "count the space*** " << count_func(text2, std::isspace);
    print_ << "count the number   " << count_function(text2, [](unsigned char c) {return std::isdigit(c); }) << end_;
    print_ << "count the xdigit   " << count_function(text2, [](unsigned char c) {return std::isxdigit(c); }) << end_;
    print_ << "count the alnum    " << count_function(text2, [](unsigned char c) {return std::isalnum(c); }) << end_;
    print_ << "count the cntrl    " << count_function(text2, [](unsigned char c) {return std::iscntrl(c); }) << end_;
    print_ << "count the graph    " << count_function(text2, [](unsigned char c) {return std::isgraph(c); }) << end_;
    print_ << "count the print    " << count_function(text2, [](unsigned char c) {return std::isprint(c); }) << end_;
    print_ << "count the lower    " << count_function(text2, [](unsigned char c) {return std::islower(c); }) << end_;
    print_ << "count the upper    " << count_function(text2, [](unsigned char c) {return std::isupper(c); }) << end_;
    print_ << "count the punct    " << count_function(text2, [](unsigned char c) {return std::ispunct(c); }) << end_;

    //for (int i = 28; i < 256; ++i) {
    //    if (std::isspace(i)) 
    //      print_ << i << " isspace [" << static_cast<char>(i)  << "]\n";

    //    if (std::isalnum(i))
    //        print_ << i << " isalnum [" << static_cast<char>(i) << "]\n";

    //    if (std::isblank(i))
    //        print_ << i << " isblank [" << static_cast<char>(i) << "]\n" ;

    //    if (std::isalpha(i))
    //        print_ << i << " isAlphabet [" << static_cast<char>(i) << "]\n" ;

    //    if (std::isdigit(i))
    //        print_ << i << " isdigit [" << static_cast<char>(i) << "]\n" ;

    //    //if (std::iscntrl(i))
    //    //    print_ << i << " iscntrl [" << static_cast<char>(i) << "]\n" ;
    //      
    //    if (i % 10 == 0) wait_;
    //}


    wait_;
    return 0;
}