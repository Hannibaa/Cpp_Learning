    //////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  
	//    C++ Concurrency in Action Book
	//    Exemples.
	// 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <algorithm>
#include <functional>
#include "MyLib/Headers/concurrency_utility.hpp"

std::chrono::sys_seconds date = std::chrono::floor<std::chrono::seconds>(now_time);

#define  DATE               std::chrono::floor<std::chrono::seconds>(now_time)
#define  ERASE_AT(x,y)      synprint_ << MOVETO(x, y) << ERASELINE

bool stop = false;


// stoper function that change the stat of stop to true if pressed some char

void thread_stoper(char c = 'q') {
	std::thread t([=] {
		while (true) {
			if (_getch() == c) {
				stop = true;
				break;
			}
		}
		});

	t.detach();
}

#define EXEMPLE10

#ifdef EXEMPLE10


int main() {

	Print_(color::Green, "today : ") << date << end_;
	thread_stoper();

	while (!stop) {
		print_ << MOVETO(2,5) << DATE << end_;
	}

	wait_;
	print_ << "program end..." << end_;
	return 0;
}




#endif // EXEMPLE10


#ifdef EXEMPLE9

std::mutex mtx;

void make_string(std::string& str, int length) {
	for (int k = 0; k != length; ++k) {
		std::lock_guard<std::mutex> lock(mtx);
		str.push_back(rand() % 26 + 65);
	}
}

void make_string1(std::string& str, char c, int length) {
	for (int i = 0; i != length; ++i) {
		std::lock_guard lock(mtx);
		str.push_back(c);
	}
}

void make_string2(std::string& str, int length) {
	for (int k = 0; k != length; ++k) {
		std::scoped_lock scp_lock(mtx);
		str.push_back(rand() % 26 + 65);
	}
}

void transfer(std::string& dest, std::string& source) {
	size_t length = std::min(dest.size(), source.size());

	for (int k = 0; k != length; ++k) {
		dest.push_back(source[length - 1 - k]);
		source.pop_back();
	}

}

void f(std::string& str, int n_threads, int length) {
	std::vector<std::thread> vthreads;

	int l = length / n_threads;

	for (int i = 0; i != n_threads; ++i) {
		vthreads.push_back(std::thread(make_string1, std::ref(str), rand()%26 + 65, l));
	}

	for (auto& e : vthreads) e.join();
}

int main() {

	Print_(color::Green, "Pass reference to thread") << end_;
	std::string str;

	f(str, 10, 1000);

	print_ << "string : " << str.size() << " : " << str << end_;

	return 0;
}

#endif // EXEMPLE9










#ifdef EXEMPLE8
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    OWNER OF THREAD MOVING.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

std::mutex io_mutex;
void f(std::string_view name) {
	{   // effect without parathesis and with 
		// get lock entire code but with parenthesis only print will lock.
		std::lock_guard<std::mutex> lg(io_mutex);
		print_ << name << " thread id " << thread_id << end_;
	}
	Sleep(Seconds(1));
}

int main() {
	std::thread thr1(f, "one");
	std::thread thr2(f, "two");
	std::thread thr;

	Sleep(Seconds(3));
	thr = std::move( thr2);
	//thr2 = std::thread([] {
	//	print_ << "new thread " << thread_id << end_;
	//	});

	thr.join();
	thr2.join();
	thr1.join();
	print_ << "------------ End -------------\n";
	return 0;
}






#endif // EXEMPLE8










#ifdef EXEMPLE7
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    MUTEX AND LOCK GUARD.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////
std::mutex io_mutex;
void f(std::string_view name) {
	{   // effect without parathesis and with 
		// get lock entire code but with parenthesis only print will lock.
		std::lock_guard<std::mutex> lg(io_mutex);
		print_ << name << " thread id " << thread_id << end_;
	}
	Sleep(Seconds(1));
}

int main() {
	std::thread thr1(f, "one");
	std::thread thr2(f, "two");


	thr2.join();
	thr1.join();
	print_ << "------------ End -------------\n";
	return 0;
}



#endif // EXEMPLE7



#ifdef TEXT_EDITOR

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    Making very tiny text editor -- 
//    
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// data
std::string buffer;
std::vector<std::string> vBuffers;
// print date in screen 
void print_date_at(int x, int y) {
	while (true) {
		if (stop) break;
		date = std::chrono::floor<std::chrono::seconds>(now_time);
		synprint_ << MOVETO(x, y) << "Date : [" << date << "]";
		Sleep(Seconds(1));
		synprint_ << MOVETO(x, y) << ERASELINE;
	}
}

void print_line_at(int line, int length = 65, char c = '-') {
	std::string _line(length, c);
	synprint_ << MOVETO(1, line) << _line;
}

// WE USE TWO GETCH() FUNCTION AS TWO THREADS
void get_text(int x, int y, std::string& buffer, std::vector<std::string>& vBuffers) {
	int c{};
	while (true) {
		if (stop) break;
		c = _getch();
		if (c == ESCAPE) stop = true;
		if (c == CR) {
			//vBuffers.push_back(buffer);
			vBuffers.insert(vBuffers.begin(), buffer);
			buffer.clear();
			synprint_ << MOVETO(x, y) << ERASELINE;
			for (int j = 0; j < 3; ++j)
				synprint_ << MOVETO(2, 20 + j) << ERASELINE;
			ERASE_AT(1, 30);
		}
		buffer.push_back(static_cast<char>(c));
		synprint_ << MOVETO(x, y) << buffer;
		synprint_ << MOVETO(1, 30) <<
			CELL(7,left,"CR | ")<< CELL(3,right, buffer.size()) <<
			CELL(12,right,"| Vsize | ")<< CELL(3,right, vBuffers.size());
		//synprint_ << MOVETO(x, y) << ERASELINE;
	}
}

int main() {
	std::string buffer2;
	std::vector<std::string> vBuffers2;

	print_line_at(2);
	print_line_at(4);
	print_line_at(6);
	print_line_at(8);
	std::thread thr1(print_date_at, 20, 1);
	std::thread thr2(get_text, 1, 3, std::ref(buffer), std::ref(vBuffers));
	std::thread thr3(get_text, 1, 5, std::ref(buffer2), std::ref(vBuffers2));

	thr2.join();
	thr1.join();
	thr3.join();
	
	if (stop) {
		esc::cls();
		print_ << std::string(65,'-') << end_;
		for (const auto& str : vBuffers)
			print_ << str << end_;
		print_ << std::string(65,'-') << end_;


		print_ << std::string(65,'-') << end_;
		for (const auto& str : vBuffers2)
			print_ << str << end_;
		print_ << std::string(65,'-') << end_;
	}

	return 0;
}

#endif // TEXT_EDITOR


#ifdef EXEMPLE6
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    start one serios project 
//    input line of string and after 64 char push in other editing windows and
//    start new line.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

std::mutex  mutex_date;
std::string buffer;
std::vector<std::string> vBuffers;

void affich_date_at(int x, int y) {
	while (true) {
		if (stop) break;
		//mutex_date.lock();
		date = std::chrono::floor<std::chrono::seconds>(now_time);
		//mutex_date.unlock();
		synprint_ << MOVETO(x, y) << "time in thread id " << thread_id << " is " << date;
		Sleep(Seconds(1));
		synprint_ << MOVETO(x, y) << ERASELINE;
	}
}

void get_text(int x, int y) {
	int c{};
	while (true) {
		if (stop) break;
		c = _getch();
		if (c == ESCAPE) stop = true;
		if (c == CR) {
			//vBuffers.push_back(buffer);
			vBuffers.insert(vBuffers.begin(), buffer);
			buffer.clear();
			synprint_ << MOVETO(x, y) << ERASELINE;
			for (int j = 0; j < 3; ++j)
				synprint_ << MOVETO(2, 20 + j) << ERASELINE;
		}
		buffer.push_back(static_cast<char>(c));
		synprint_ << MOVETO(x, y) << buffer;
		synprint_ << MOVETO(1, 30) << "CR | " << buffer.size() << " | Vsize | " << vBuffers.size();
		//synprint_ << MOVETO(x, y) << ERASELINE;
	}
}

void print_buffers(size_t n) {
	while (true) {
		if (stop) break;
		int sz_buf = vBuffers.size();
		for (int j = 0; j < std::min(n,vBuffers.size()); ++j) {
			synprint_ << MOVETO(2, 20 + j) << vBuffers[j];
		}
	}
}


int main() {

	std::thread thr1(affich_date_at, 2, 4);
	std::thread thr2(affich_date_at, 2, 5);
	std::thread thr3(get_text, 2, 7);
	std::thread thr4(print_buffers, 3);

	//thread_stoper();

	thr1.join();
	thr2.join();
	thr3.join();
	thr4.join();

	print_ << "----------- End ------------- " << end_;

	return 0;
}



#endif // EXEMPLE6




#ifdef EXEMPLE5
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    Detaching a thread to  handle other documents(clocks)
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void open_document_and_display_gui(std::string);

void edit_document(std::string file_name) {
	open_document_and_display_gui(file_name);
	
	while (!done_editing()) {
		user_command cmd = get_user_input();

		if (com.type == open_new_decument) {
			std::string const new_name = get_file_name_from_user();
			std::thread t(edit_document, new_name);
			t.detach();
		}
		else {
			process_user_input(cmd);
		}
	}

}

#endif // EXEMPLE5


#ifdef EXEMPLE4

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    Detaching a thread to handle other decuments 
//    1. run thread in backround when function already exit.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////

bool stop = false;

void func1(int x, int y) {
	while (true) {
		if (stop) break;
		synprint_<< MOVETO(x,y) << "time in thread id " << thread_id << " is " << time_now;
		Sleep(Seconds(1));
		synprint_ << MOVETO(x, y) << ERASELINE;
	}
}

void threadfunc1() {
	std::thread thr(func1, 1, 5);
	thr.join();
	printm_(1,8) << "end of function" << end_;
}


int main() {
	printm_(20, 1) << "main thread id " << thread_id << end_;

	std::thread thr1(func1,1,2);
	std::thread thr2(func1, 1, 3);
	std::thread thrStop([] {
		while (true) {
			if (_getch() == 'q') {
				stop = true;
				break;
			}
		}
		}
	);

	threadfunc1();

	thr2.join();
	thr1.join();
	thrStop.join();

	print_ << "end of program " << end_;
	return 0;
}


#endif // EXEMPLE4



#ifdef EXEMPLE3
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Exemple 3 thread guard   
// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class thread_guard {
	std::thread& t;
public:
	explicit thread_guard(std::thread& _t)
		:t(_t)
	{}

	~thread_guard() {
		if (t.joinable()) {
			t.join();
		}
	}

	thread_guard(thread_guard const&) = delete;
	thread_guard& operator=(thread_guard const&) = delete;
};


int main() {

	int stat = 0;


	return 0;
}

#endif // EXEMPLE3



#ifdef EXEMPLE2
// A function that returns while a thread still has access to locale variables

void do_something(int& i) {
	i << 4;
	i = i & 0xffffff00;
}

struct func {
	int& i;
	func(int& _i) :i{ _i } {}

	void operator()() {
		for (unsigned j = 0; j < 100 ; ++j) {
			do_something(i); // access to dangling reference.
			Sleep(Milliseconds(200));
			print_ << "i = " << i << end_;
		}
	}
};

void op() {
	int stat = 0;
	func my_func(stat);
	std::thread my_thread(my_func);
	my_thread.detach();               
}

int main() {

	op();


	print_ << "end of program 2...";
	return 0;
}

#endif











#ifdef EXEMPLE1
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 
	//    EXEMPLE ONE 
	// 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////

// Construct thread definition
std::string text_{ "hello" };

void some_work(std::string_view text) {
	text_ += text;
	Sleep(Milliseconds(500));
}

struct SomeWork {
	void operator() (std::string_view text) const {
		text_ += text;
		Sleep(Milliseconds(800));
	}
};


int main() {

	std::thread thr1(some_work, "thread 1");
	std::thread thr2((SomeWork{}), "thread 2");

	SomeWork somework;

	std::thread thr3{ somework , "thread 3"};





	thr1.join();
	thr2.join();
	thr3.join();
	print_ << "string is   " << text_ << end_;
	print_ << "end of program..." << end_;
	return 0;
}

#endif