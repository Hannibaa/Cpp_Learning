#include "Strategy.h"



// third exemple 
int main() {

	sol2::Shipe  shipe;

	shipe.DoActions();

	// after some time we need to change to combat strategy

	shipe.setStrategy(std::unique_ptr<sol2::Combat>());

	shipe.DoActions();

	wait_;
	print_ << "end of program..." << end_;
	return 0;
}





// second exemple using std::unique_ptr
int main2() {

	using UniqueSort = std::unique_ptr<sol1::ISorts>;

	std::vector<UniqueSort>  alg;

	alg.push_back(std::make_unique<sol1::InsersionSort>());
	alg.push_back(std::make_unique<sol1::InsersionSort>());
	alg.push_back(std::make_unique<sol1::QuickSort>());

	for (const auto& a : alg) a->Sort();


	wait_;
	print_ << "program end..." << end_;
	return 0;
}




// first exemple
int main1() {

	sol1::ISorts* sort = new sol1::InsersionSort;

	sort->Sort();
	if (dynamic_cast<sol1::BubbleSort*>(sort)) 
		dynamic_cast<sol1::BubbleSort*>(sort)->Sort();

	delete sort;
	wait_;
	return 0;
}