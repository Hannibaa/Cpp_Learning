#pragma once
#include <vector>
// Observer interface
class IObserver {
public:
	virtual ~IObserver() = default;
	virtual void update(float temp, float humidity, float pressure) = 0;
};

// Subject Weather Stat
class WeatherStation {
private:
	float temperature;
	float humidity;
	float pressure;
	std::vector<IObserver*>   vObs;

public:
	void registerObserver(IObserver* observer) {
		vObs.push_back(observer);
	}

	void removeObserver(IObserver* observer) {

	}

	void notifyObserver() {
		for (auto obs : vObs) {
			obs->update(temperature, humidity, pressure);
		}
	}

	void setMesure(float temp, float hum, float pr) {
		temperature = temp;
		humidity = hum;
		pressure = pr;
		notifyObserver();
	}
};