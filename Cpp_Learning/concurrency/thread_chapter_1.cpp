    //////////////////////////////////////////////////////////////////////////////////////////////////////////
	//  
	//    C++ Concurrency in Action Book
	//    Exemples.
	// 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <algorithm>
#include "MyLib/Headers/concurrency_utility.hpp"

std::chrono::sys_seconds date = std::chrono::floor<std::chrono::seconds>(now_time);

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

#define EXEMPLE6

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