#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "MyLib/dictionary/dictionary.h"

using namespace std;

auto print_10Items = [](const auto Container) {
	vu::print_container(Container.begin(), Container.begin() + (Container.size() > 10 ? 10 : Container.size()), 1);
	return;
};


int main()
{
	std::string TF[]{ "False","True" };

    std::string dictionary_path = R"(C:\Users\Acer\source\MyLib\dictionary\words_alpha.txt)";

	print_ << dictionary_path << end_;

	dictionary::Dictionary dictionar(dictionary_path);

	auto dic_a = dictionar.get_dictionar_alphabet('a');

	auto dic_z = dictionar.get_dictionar_alphabet('z');

	vu::print_container(dic_a.begin(), dic_a.begin() + 24, 12);
	newline_;
	vu::print_container(dic_z.end() - 25, dic_z.end(), 12);

	// we like to looking some word 
	std::string in_word{};

__find:
	newline_;
	Print_(color::Yellow, "Give me word :") << end_;
	cin >> in_word;
	newline_;
	print_ << "is there word [" << in_word << "] : " << TF[dictionar.find(in_word)] << end_;

	print_ << "tap (y)es for more search (n)o for close programme : " << end_;
	char yn{};
	cin >> yn;

	if (yn == 'y') goto __find;

	// looking for range of word that contain subword subword
	newline_;
	Print_(color::Yellow, "Give me sub word : ") << end_;
	in_word.clear();
	cin >> in_word;

	auto all_word   = dictionar.find_all_words(in_word);
	auto all_words1 = dictionar.find_all_suffix(in_word);
	auto all_words2 = dictionar.find_all_prefix(in_word);
    
	print_ << "the words that have subword all_word " << in_word << " are " << all_word.size() << end_ ;
	print_ << "the words that have subword suffix   " << in_word << " are " << all_words1.size() << end_ ;
	print_ << "the words that have subword prefix   " << in_word << " are " << all_words2.size() << end_ ;
	wait_;
	print_ << "print all words : " << end_;
	vu::print_container(all_word.begin(), all_word.begin() + (all_word.size() > 10 ? 10 : all_word.size()), 1);
	wait_;
	print_ << "print all suffix : " << end_;
	print_10Items(all_words1);
	wait_;
	print_ << "print all prefix : " << end_;
	print_10Items(all_words2);
	newline_;

	cin.get();
	return 0;
}