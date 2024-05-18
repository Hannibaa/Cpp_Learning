#include <Windows.h>
#include <iostream>
#include <MyLib/Console_Library/Event_Windows.h>


#define   end_  '\n'

/*
          this section for testing Message boxes of windows
          1. MessageBox :
          int MessageBox(
          [in, optional] HWND    hWnd,
          [in, optional] LPCTSTR lpText,
          [in, optional] LPCTSTR lpCaption,
          [in]           UINT    uType
);
*/


int main() {

    std::cout << "Message Box demo : " << end_;

    UINT mb_info[10] = {-1,
        MB_ICONASTERISK,
        MB_ICONEXCLAMATION,
        MB_ICONERROR,
        MB_ICONHAND,
        MB_ICONINFORMATION,
        MB_ICONQUESTION,
        MB_ICONSTOP,
        MB_ICONWARNING,
        MB_OK
    };

    unsigned int k{};

    while (true) {
        if (KeyReleased(_u('A'))) {
            MessageBeep(mb_info[k]);
            std::cout << "Beep at " << k << " , " <<  mb_info[k] << end_;
        }

        if (Get_Escape()) break;

        if (KeyReleased(VK_UP)) {
            k = (++k) % 10;
        }

        if (KeyReleased(VK_DOWN)) {
            k = (--k) % 10;
        }
    }

    std::cout << "end fo program" << end_;
    return 0;
}