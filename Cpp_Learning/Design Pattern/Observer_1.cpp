#include <iostream>
#include "MyLib/Console_Library/escape_code.h"
#include "Observer_1.h"


class Display : public IObserver {
public:

	Display(WeatherStation& wst) {
		wst.registerObserver(this);
	}

	 void update(float t, float h, float p) override {
		print_ << "temprature : " << t << end_;
		print_ << "humidity   : " << h << end_;
		print_ << "pressure   : " << p << end_;
	}
};

class ReDisplay : public IObserver {
public:
	void update(float t, float h, float p) override {
		print_ << "[" << t << " , " << h << " , " << p << end_;
	}
};

int main() {

	Print_(color::Green, "Hello Observer Pattern") << end_;

	WeatherStation    station;

	Display   d1(station);
	ReDisplay rd1;


	station.registerObserver(&rd1);

	station.setMesure(23, 400, 1200);
	
	
	wait_;
	return 0;
}