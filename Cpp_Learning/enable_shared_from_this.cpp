#include <iostream>
#include <memory>

class Bad {
public:
	void Print() {
		if (getSharedPtr().use_count() == 3) {
			std::cout << "Doing " << getSharedPtr().use_count() << '\n';
		}
		else
		{
			std::cout << "Doing bad " << getSharedPtr().use_count() << '\n';
		}
	}

	std::shared_ptr<Bad> getSharedPtr() {
		return std::shared_ptr<Bad>(this);
	}
};


class Int : public std::enable_shared_from_this<Int> {
public:

	void Print() {
		std::cout << "count " << this->shared_from_this().use_count() << '\n';
	}
};


int main() {

	Int i;

	i.Print();

	std::cin.get();
	return 0;
}