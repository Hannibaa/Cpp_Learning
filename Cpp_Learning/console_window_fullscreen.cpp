#include <MyLib/Console_Library/Event_Windows.h>
#include <iostream>

#define   end_    '\n'


int main() {

	std::cout << "Hello ! " << end_;

	//SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	auto pairSize = WIN_CONSOLE::;
	std::cout << "minized console size    : " << pairSize.first.X << " , " << pairSize.first.Y << end_;
	std::cout << "maximum : " << pairSize.second.X << " , " << pairSize.second.Y << end_;

	//if (ShowWindow(GetConsoleWindow(), SW_MAXIMIZE))
	if (fullscreen_console())
		std::cout << "success" << end_;
	else
		std::cout << "not success : " << GetLastError() << end_;

	// we wont to get console resolution 
	pairSize = get_console_size();
	std::cout << "fullscreen console size : " << pairSize.first.X << " , " << pairSize.first.Y << end_;
	std::cout << "maximum : " << pairSize.second.X << " , " << pairSize.second.Y << end_;

	std::cin.get();
	std::cout << "End of program" << end_;
	return 0;

}