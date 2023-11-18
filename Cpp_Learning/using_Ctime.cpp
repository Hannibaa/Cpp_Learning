#include <iostream>
#include <time.h>
#include "MyLib/Console_Library/escape_code.h"

//#pragma warning( disable : 4700)

int main()
{
	time_t timer;
	tm* t;
	time(&timer);
	auto err = localtime_s(t, &timer);
	char buf[80]{};

	strftime(buf, 80, "%h:%m:%s", t);

	print_ << "time is " << buf << end_;

	//wprint_ << _ws(htllo) << wend_;

	//print_ << "what is : " << t_st->tm_year << end_;
	//print_ << "what is : " << t_st->tm_mon << end_;
	//print_ << "what is : " << t_st->tm_wday << end_;
	//print_ << "what is : " << t_st->tm_mday << end_;
	//print_ << "what is : " << t_st->tm_yday << end_;
	//print_ << "what is : " << t_st->tm_hour << end_;
	//print_ << "what is : " << t_st->tm_min << end_;
	//print_ << "what is : " << t_st->tm_sec << end_;
	//print_ << "what is : " << t_st->tm_isdst << end_;

	std::cin.get();
	return 0;
}