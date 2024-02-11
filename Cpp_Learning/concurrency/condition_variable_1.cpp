/*
    TOPIC : Condition variable in C++ threading
    Important Point : CV are used for two purpose
       a. Notify other threads
       b.  Waiting for some conditions

    1. Condition variable allows running threads to wait on some conditions and once those condition
       are met the waiting thread is notified using :
       a. notify_one();
       b. notify_all();
    2. You need mutex to use condition variable.
    3. If some  thread want to wait on some condition them it has to do these things:
       a. Acquire  the mutex lock using std::unique_lock<std::mutex> lock(m);.
       b. Execute wait, wait_for or wait_untill. the wait operations atomically release the mutex 
          and suspend the execution of the thread.
       c. When the condition variable is notified, the thread is awakened, and the mutex is 
          atomically reacquired. The thread should then check the condition adn resume waiting if the 
          wake up was spurious.

    NOTE:
    1. Condition variables are used to synchronize two or more threads.
    2. Best use case of condition variable is Producer/Consumer problem.
*/


#include <iostream>
#include <syncstream>
#include <conio.h>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "MyLib/Console_Library/escape_code.h"

std::condition_variable cv;
std::mutex mut;
long balance = 0;

bool stop = false;

void addMoney(int money) {
    std::lock_guard<std::mutex> lg(mut);
    balance += money;
    std::osyncstream(std::cout) << MOVETO(3,4)
        << "Amount added Current Balance :"<< balance << " |" <<
        std::this_thread::get_id() << end_;
    cv.notify_one();
}

void withdrawMoney(int money) {
    std::unique_lock<std::mutex> ul(mut);
    cv.wait(ul, [] {return balance != 0 ? true : false; });

    if (balance >= money) {
        balance -= money;
        std::osyncstream(std::cout)  << MOVETO(3,6)
            << "Amount deducted : " << money << end_;
    }
    else {
        std::osyncstream(std::cout) << MOVETO(3,7)
            << "Amount Can't Be deduced, Current Balance is less than" << money << end_;
        balance += static_cast<int>(0.1f * float(money));
    }

    std::osyncstream(std::cout) << MOVETO(3,8)
        << "Current balance is :" << balance << " |" << 
        std::this_thread::get_id() << end_;
}

int main() {
    std::cout << "Main thread Id : " << std::this_thread::get_id() << end_;
    //std::thread t1(withdrawMoney, 100);
    //std::thread t2(addMoney, 100);

	std::thread thrStop([] {
        label1:
		char c = _getch();
        if (c == 's' || c == 'S') stop = true;
        else goto label1;

		});

	std::thread t3([] {
		while (true) {
			addMoney(101);
            if (stop) break;
		}
		});

    std::thread t4([] {
        while (true) {
            withdrawMoney(100);
            if (stop) break;
        }
        });

    //t1.join();
    //t2.join();

    t3.join();
    t4.join();
    thrStop.join();

    std::cin.get();
    return 0;
}