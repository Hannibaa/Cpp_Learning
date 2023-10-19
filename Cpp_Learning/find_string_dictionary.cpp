#include <iostream>
#include <algorithm>
#include <chrono>
#include <filesystem>
#include <string>
#include <string_view>
#include <MyLib/stringfunctionhelper.h>
#include "MyLib/Console_Library/escape_code.h"
#include <MyLib/random_vector.h>
#include <MyLib/vector_utility1.h>


namespace fs = std::filesystem;

// laoding all dictionary in vector
// calculate time of loading

std::vector<std::string> load_dictionary(const fs::path& dictionar_location) {

	// should be existing file or close application
	if (!fs::exists(dictionar_location)) {
		std::cout << "file corresponding a dictionary not exit, or error in loading file\n";
		return {};
	}

	// creating file 
	std::ifstream ifs{ dictionar_location };
	if (!ifs.is_open()) {
		std::cout << ESC::Colors::_YELLOW_FG << "Error in founding file" << ESC::Colors::_RESETMODE << end_;
		return {};
	}

	// load all word to memory as vector
	std::chrono::duration<float> duration{};
	auto tp = std::chrono::steady_clock::now();

	std::vector<std::string> vec_words{};
	std::string word{};

	while (ifs >> word) {
		vec_words.push_back(word);
	}
	duration = std::chrono::steady_clock::now() - tp;
	print_ << "time of loading " << duration << end_;
	ifs.close();
	return vec_words;
}


// Load text file in vector of text (lower case) for search and look up.

std::vector<std::string> load_text_file(const std::string& filename) {

	fs::path dictionar_location{ filename };

	// should be existing file or close application
	if (!fs::exists(dictionar_location)) {
		std::cout << "file corresponding a dictionary not exit, or error in loading file\n";
		return {};
	}

	// creating file 
	std::ifstream ifs{ dictionar_location };
	if (!ifs.is_open()) {
		std::cout << ESC::Colors::_YELLOW_FG << "Error in founding file" << ESC::Colors::_RESETMODE << end_;
		return {};
	}

	// load all word to memory as vector
	std::chrono::duration<float> duration{};

	std::vector<std::string> vec_words{};
	std::string text_line{};
	auto tp = std::chrono::steady_clock::now();

	while ( std::getline(ifs,text_line) ) {
		auto Vwords = Str::get_alpha_words(text_line);
		for( auto& word : Vwords)
		vec_words.push_back(Str::str_tolower(word));
	}

	duration = std::chrono::steady_clock::now() - tp;
	print_ << "time of loading " << duration << end_;
	ifs.close();

	return vec_words;
}



// LOAD A PART OF DICTIONARY, ONE ALPHABATE CHAR = 'a', AND COUNT HOW MUCH NUMBER OF WORDs

std::vector<std::string> load_dictionary_alphabet(std::ifstream& ifs,char Char) {

	// check file if is it open?
	// check Char is alphabetic and not numberics?
	// laoding string of char to vector string;

	Char = std::tolower(Char);

	std::string word{};
	std::vector<std::string> tempVec;

	while (ifs >> word) {
		
		if (Char == std::tolower(word[0]))
		{
			tempVec.push_back(Str::str_tolower(word));
		}
	}

	return tempVec;
}




//  FUNCTION LOOKING FOR STRING IN 

bool find_word(const std::string_view word, const std::vector<std::string>& dictionary) {

	auto find = std::find(dictionary.begin(), dictionary.end(), word);

	if ( find == dictionary.end() ) {
		print_ << ESC::Colors::_GREEN_FG << " Not Found this Word [" << 
			      ESC::Colors::_RED_FG << word << "]" << RESETMODE << end_;
		return false;
	}
	else {
		print_ << "Word found it " << word << " is founded " << *find << end_;
		return true;
	}
}



// FUNCTION, found all word that have subword

std::vector<std::string> find_words_has_subword(const std::string_view subword, const std::vector<std::string>& dictionary)
{
	std::string::size_type    find_{};
	std::vector<std::string>  vec_found;

	auto tp = std::chrono::steady_clock::now();
	std::chrono::duration<float> d{};

	for (auto& word : dictionary) {
		find_ = word.find(subword);

		   if (find_ != std::string::npos ) {
			   vec_found.push_back(word);
		   }

	}

	d = std::chrono::steady_clock::now() - tp;
	std::cout << "time that taken to look at word : " << d << " seconds\n";

	return vec_found;
}


int main() {

	    fs::path dictionary_path = R"(C:\Users\Acer\source\MyLib\dictionary\words_alpha.txt)";

		std::string file_text = "Text.txt";
	    
	    auto dictionary = load_text_file(file_text);
	    
	    vu::print_container(dictionary.begin(),dictionary.end(), 10);

		newline_;

		auto Vwords = find_words_has_subword("a", dictionary);

		newline_;

		vu::print_container(Vwords, 12);


	wait_;
	return 0;
}


//int main() {
//
//	std::string TF[2]{ "False", "True" };
//
//	fs::path dictionary_path = R"(C:\Users\Acer\source\MyLib\dictionary\words_alpha.txt)";
//
//	auto dictionary = load_dictionary(dictionary_path);
//
//	vu::print_container(dictionary.begin(),dictionary.begin()+10);
//
//	std::string word{};
//
//	// ENTER THE WORD HERE
//	print_ << "Enter the word :" << end_;
//	std::cin >> word;
//
//	word = Str::str_tolower(word);
//
//	print_ << "The word for searching is [" << word << "]\n";
//
//	auto Bool = find_word(word, dictionary);
//
//	print_ << "is found it? " << ESC::Colors::_YELLOW_FG << TF[Bool] << RESETMODE << end_;
//
//
//	wait_;
//	return 0;
//}