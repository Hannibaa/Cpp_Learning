#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <windows.h>

#include <include/console/escape_code.h>



bool bStop = false;

int main() {
	set_escape_mode;
	
	std::thread Stop([] {
		while (true) {
			char c = _getch();
			if (c == ESCAPE) {
				bStop = true;
				break;
			}
		}
		});
	Stop.detach();

	Print_(color::Green, "Program Simulate time") << end_;

	// start :
	using namespace std::chrono_literals;

	auto start_time = std::chrono::steady_clock::now();
	bool timer_runing = true;

	// Application
	while (true) {
		Print_(color::Yellow, "While Loop") << end_;

		if (bStop) { break; }

		if (timer_runing) {
			auto now = std::chrono::steady_clock::now();
			float d = std::chrono::duration<float>(now - start_time).count();
			if ( d > 1.23f ) {
				//timer complete
				Print_(color::Red, "Timer finish") << end_;
				timer_runing = false;
			}
		}
		else {
			Print_(color::Blue, "timer runing out ") << end_;
			break;
		}

		//std::this_thread::sleep_for(500ms);
	}


	wait_;
	return 0;
}