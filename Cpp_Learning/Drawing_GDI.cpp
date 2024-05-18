#include <thread>
#include <conio.h>
#include <Windows.h>

#include <MyLib/random_vector.h>

bool bStop = false;

void LunchThreadStop() {
	std::thread thr([] {
		while (true) {
			if (_getch() == 0x1b) {
				bStop = true;
				break;
			}
		}
		});

	thr.detach();
}

int main() {
	LunchThreadStop();
	RECT  rect;
	RECT  Crect;

	HWND  hDesktop = GetDesktopWindow();
	HWND  hConsole = GetConsoleWindow();
	GetWindowRect(hDesktop, &rect);
	GetWindowRect(hConsole, &Crect);
	printf("windows : %d %d %d %d \n", rect.left, rect.right, rect.bottom, rect.top);
	printf("windows : %d %d %d %d",Crect.left, Crect.right, Crect.bottom, Crect.top);

	auto style = GetWindowLong(hConsole, GWL_STYLE);
	//style &= ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX & ~WS_SIZEBOX;
	style &= ~WS_CAPTION & ~WS_BORDER & ~WS_SIZEBOX & ~WS_HSCROLL & ~WS_VSCROLL;

	SetWindowLong(hConsole, GWL_STYLE,  style );
	SetWindowPos(hConsole, NULL, 50, 50, 0, 0, SWP_NOSIZE | SWP_FRAMECHANGED);

	std::thread thrRect([] {
		HWND  hConsole = GetConsoleWindow();
		HDC   screen = GetDC(hConsole);  // Retrieve for entire screen

		POINT    vPoint[3] = { {20,20}, {20,100}, {500,100} };


		while (!bStop) {
			Rectangle(screen, 0, 500, 200, 200);
			Ellipse(screen, 500, 300, 700, 600);
			//LineTo(screen, 100, 100);
			//LineDDA(0, 0, 200, 200, NULL, NULL);

			Polygon(screen, vPoint, 3);
		}

		});


	thrRect.join();

}