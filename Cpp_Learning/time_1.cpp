/* 
        KADDA AOUES EXEMPLES 
        1. CHRONO DATE AND TIME 
*/

#include <iostream>
#include <chrono>
#include <string>
#include <MyLib/chrono/Timer.h>
#include <MyLib/chrono/to_day.h>

#define end_ '\n'

int main() {

    std::cout << "to day is " << ToDay::date() << end_;

    std::cout << "day name is " << ToDay::day_name() << end_;

    std::cout << "hour is : " << ToDay::hour() << end_;


    std::cin.get();
    return 0;
}