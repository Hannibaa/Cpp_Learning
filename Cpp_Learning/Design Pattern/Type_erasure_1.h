#pragma once
#include <MyLib/Console_Library/escape_code.h>

/*        Using  Hierarchy                                                                    */

class Command {
public:
	virtual void operator()(int) const = 0;
};

class PrintCommand : public Command {
public:
	virtual void operator()(int _instruction_id) const override {
		Print_(_instruction_id, "color same instruction id ") << _instruction_id << end_;
	}
};

class SearchCommand : public Command {
	virtual void operator()(int _search_item) const override {
		Print_(color::Green, "Search Instruction ") << _search_item << end_;
	}
};

class ExecuteCommand : public Command {
	virtual void operator()(int _execute_id) const override {
		Print_(color::Fuchsia, "Execute : ") << _execute_id << end_;
	}
};
