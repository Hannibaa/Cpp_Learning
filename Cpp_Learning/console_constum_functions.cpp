#include <Windows.h>
#include <thread>
#include <MyLib/Console_Library/Event_Windows.h>
#include <iostream>

LONG g_oldStyle{};

void Get_ConsoleWindow_Style() {
	HWND  hwndConsole = GetConsoleWindow();

	g_oldStyle = GetWindowLong(hwndConsole, GWL_STYLE);
}

bool Set_Window_Style(HWND hwnd, LONG style) {
	// set the new style
	SetWindowLong(hwnd, GWL_STYLE, style);
	if (SetWindowPos(hwnd, NULL, 0,0 , 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED))
		return true;
	else
		return false;

}

bool Get_Only_Console_Border(){
	HWND  hwndConsole = GetConsoleWindow();

	auto style = GetWindowLong(hwndConsole, GWL_STYLE);

	// modify style
	style &= ~WS_SIZEBOX; // unable resizing.
	style &= ~WS_SYSMENU; // remove system menu
	style &= ~WS_HSCROLL; // remove scrolling horizotall
	style &= ~WS_VSCROLL; // remove vertical scrolling
	//...

	// set the new style
	return Set_Window_Style(hwndConsole, style);
}

bool Set_Old_Style() {
	HWND  hwndConsole = GetConsoleWindow();
	return Set_Window_Style(hwndConsole, g_oldStyle);
}



int main() {

	Get_ConsoleWindow_Style();

	std::cout << "this program demostrate how to remove borders.\n";

	SetConsoleTitle(L"This for testing Window Styles");

	std::thread thr([] {
		while (true) {
			// Set old style to console windows
			if (KeyReleased(_u('A'))) {
				if (Set_Old_Style())
					std::cout << "return back to console title bar\n";
				else
					std::cout << "There are some error\n";
			}

			// remove title bar and some staf from window bar
			if (KeyReleased(_u('B'))) {
				if (Get_Only_Console_Border())
					std::cout << "console without title bar\n";
				else
					std::cout << "There are some error\n";
			}

			if (get_out()) break; 
		}
		});

	
	thr.join();

	std::cin.get();
	return 0;
}