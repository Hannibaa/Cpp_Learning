#include <iostream>
#include <ctime>
#include "MyLib/Console_Library/escape_code.h"

#pragma warning( disable : 4996)

/*
       struct tm* gmtime(const time_t* timer);
       struct tm* localtime(const time_t* timer);

	   struct tm {
              int tm_sec;
              int tm_min
              int tm_hour;
              int tm_mday;
              int tm_mon;
              int tm_year;
              int tm_wday;
              int tm_yday;
              int tm_isdst;
              };

              #define CLOCKS_PER_SEC  //  implementation defined
              std::clock_t  clock();

                 struct       timespec;     // (since C++17)
                 std::time_t  tv_sec;    	// whole seconds – >= 0
                 long         tv_nsec;	    //  nanoseconds – [0, 999999999]
                 int timespec_get( std::timespec* ts, int base)  // (since C++17)
                 #define TIME_UTC                               // implementation-defined (since C++17)
*/
std::clock_t _befor = clock();

int main()
{
    std::clock_t _start =  clock();

    Print_(color::Fuchsia, "Befor main :[") << _befor << end_;
    
    Print_(color::Fuchsia, "start :[") << _start << end_;

	time_t mytime;
	time(&mytime);

	std::tm* time1;
	std::tm* time2;

	time1 = gmtime(&mytime);
    time2 = localtime(&mytime);

    Print_(color::Green, "CLOCKS_PER_SEC : [") << COLOR(color::Red, CLOCKS_PER_SEC) << end_;

	print_ << "the current time : " << ctime(&mytime) << end_;

	print_ << "time from epoch take in size_t is : " << mytime << end_;

    print_ << "time hour  : " << time1->tm_hour << end_
           << "time min   : " << time1->tm_min << end_
           << "time sec   : " << time1->tm_sec << end_
           << "-----------------------------------" << end_
           << "date day   : " << time1->tm_mday << end_
           << "date month : " << time1->tm_mon << end_
           << "date year  : " << time1->tm_year << end_
           << "-----------------------------------" << end_
           << "date day   : " << time1->tm_wday << end_
           << "date day   : " << time1->tm_yday << end_
           << "date day   : " << time1->tm_isdst << end_
           << "-----------------------------------" << end_
           << "locale time function : " << end_
           << "time hour  : " << time2->tm_hour << end_
           << "time min   : " << time2->tm_min << end_
           << "time sec   : " << time2->tm_sec << end_;


    std::clock_t _end = clock();
    Print_(color::Fuchsia, "end :[") << _end << end_;
    Print_(color::Fuchsia, "elapsed time :[") << _end - _start << end_;

    wait_;
    esc::cls();
    Print_(color::Green, "Testing C++17 feature") << end_;
    std::timespec ts;
    std::timespec_get(&ts, TIME_UTC);
    char buf[100];
    std::strftime(buf, sizeof buf, "%D %T", std::gmtime(&ts.tv_sec));
    std::printf("Current time: %s.%09ld UTC\n", buf, ts.tv_nsec);

	std::cin.get();
	return 0;
}