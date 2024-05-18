#include <iostream>

/*
       1. In this exemple we will implement body of pure virtual function and call by some
	   function in derived class.
	   2. Overlaod and override some function name.

*/
 
class IPlayer {
public:

	virtual void draw() const = 0;

	virtual ~IPlayer() = default;
};

void IPlayer::draw() const {
	std::cout << "Draw IPlayer\n";
};

class Player : public IPlayer {
public:
	virtual void draw() const override {
		std::cout << "Draw derived Player\n";

		// we can call this here
		IPlayer::draw();
	}

	void draw(int) const {
		IPlayer::draw();
	}
};

int main() {

	Player p1;
	p1.draw();
	p1.draw(0);



	std::cin.get();
	return 0;
}