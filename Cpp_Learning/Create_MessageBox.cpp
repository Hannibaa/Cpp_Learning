#include <Windows.h>
#include <iostream>
#include <MyLib/Console_Library/Event_Windows.h>


#define   end_  '\n'
using     uint = unsigned int;

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

    // Icons in message boxes
    UINT mb_icons[9] = { -1,  // 0
        MB_ICONASTERISK,      // 1
        MB_ICONEXCLAMATION,   // 2
        MB_ICONERROR,         // 3
        MB_ICONHAND,          // 4
        MB_ICONINFORMATION,   // 5
        MB_ICONQUESTION,      // 6
        MB_ICONSTOP,          // 7
        MB_ICONWARNING,       // 8
    };

    // Buttons displayed in the message box.
    UINT mb_buttons[8] = { 
        MB_ABORTRETRYIGNORE,  // 0
        MB_CANCELTRYCONTINUE, // 1
        MB_HELP,              // 2
        MB_OK,                // 3
        MB_OKCANCEL,          // 4
        MB_RETRYCANCEL,       // 5
        MB_YESNO,             // 6
        MB_YESNOCANCEL        // 7
    };

    // Default Buttons
    UINT mb_defbuttons[4] = {
        MB_DEFBUTTON1,        // 0
        MB_DEFBUTTON2,        // 1
        MB_DEFBUTTON3,        // 2
        MB_DEFBUTTON4         // 3
    };

    // Modality of the dialog box
    UINT mb_modals[] = {
        MB_APPLMODAL,         // 0
        MB_SYSTEMMODAL,       // 1
        MB_TASKMODAL          // 2
    };

    // Specify other option
    UINT mb_options[] = {
        0,                       // 0
        MB_DEFAULT_DESKTOP_ONLY, // 1
        MB_RIGHT,                // 2
        MB_RTLREADING,           // 3
        MB_SETFOREGROUND,        // 4
        MB_TOPMOST,              // 5
        MB_SERVICE_NOTIFICATION  // 6
    };

    int return_msg{};

    auto MsgOption = [=](uint i, uint b, uint d, uint m, uint o)->uint {
        return mb_icons[i % 9] | mb_buttons[b % 8] | mb_defbuttons[d % 4] | mb_modals[m % 3]
           | mb_options[o % 7];
        };

    while (true) {

        // Get messagebox 
        if (KeyReleased(_u('A'))) {
            return_msg = MessageBoxW(NULL, L"KADDA AOUES", L"NAME", 
               MsgOption(5, 1, 0, 0, 0) ) ;
            std::cout << "Return from Message Box : " << return_msg << " | " << end_;
        }

        // break inifinit loop
        if (Get_Escape()) break;

        // Process return from message box.
        switch (return_msg) {
        case IDABORT:                // 1
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;

        case IDCANCEL:               // 2
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;

        case IDCONTINUE:               // 3
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;

        case IDIGNORE:               // 4
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;

        case IDNO:               // 5
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;    

        case IDOK:               // 6
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;

        case IDRETRY:               // 7
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;

        case IDTRYAGAIN:               // 8
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;

        case IDYES:               // 9
            // code
            std::cout << "Code is : " << return_msg << "|" << end_;

            return_msg = -1;
            break;

        case 0:                   // 10
            // code
            std::cout << "Error : " << return_msg << "|" << end_;
            std::cout << "Last Error Code : " << GetLastError() << end_;
        }

        
    }

    std::cout << "end fo program" << end_;
    return 0;
}