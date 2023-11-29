#pragma once
#include <MyLib/Console_Library/escape_code.h>

/*     Using std::function*/

class PrintCommand  {
public:
	void operator()(int _instruction_id) const {
		Print_(_instruction_id, "color same instruction id ") << _instruction_id << end_;
	}
};

class SearchCommand {
public:
	void operator()(int _search_item) const  {
		Print_(color::Green, "Search Instruction ") << _search_item << end_;
	}
};

class ExecuteCommand {
public:
	void operator()(int _task_id) const {
		Print_(color::Green, "Execute _id ") << _task_id << end_;
	}
};
