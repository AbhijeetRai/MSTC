#include <Windows.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

#define ID_TIMER 1 

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nShowCmd) {

    static TCHAR szAppName[] = TEXT ("Beeper1"); 
    HWND hwnd; 
    MSG msg; 
    WNDCLASS wndclass; 

    wndclass.style = CS_HREDRAW | CS_VREDRAW; 
    wndclass.lpfnWndProc = WndProc; 
    wndclass.cbClsExtra = 0; 
    wndclass.cbWndExtra = 0; 
    wndclass.hInstance = hInstance; 
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); 
    wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH); 
    wndclass.lpszMenuName = NULL; 
    wndclass.lpszClassName = szAppName;

    if(!RegisterClass(&wndclass)) {
        MessageBox(NULL, TEXT("Program requires Windows NT!"), szAppName, MB_ICONERROR);
        return (0);
    }

    hwnd = CreateWindow(szAppName, TEXT("Beeper1 Timer Demo"), 
                    WS_OVERLAPPEDWINDOW, 
                    CW_USEDEFAULT, CW_USEDEFAULT, 
                    CW_USEDEFAULT, CW_USEDEFAULT, 
                    NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nShowCmd); 
    UpdateWindow(hwnd); 

    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg); 
        DispatchMessage(&msg);
    }

    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static int cxClient, cyClient; 
    static BOOL fFlipFlop = FALSE; 
    HBRUSH hBrush; 
    HDC hdc; 
    PAINTSTRUCT ps; 
    RECT rc;
    static int colors[] = {0x000000FF, 0x0000FF00, 0x00FF0000};
    static int iColorIndex = 0;
    static int fonts[] = {DEFAULT_GUI_FONT, OEM_FIXED_FONT};
    static int iFontIndex = 0;

    switch(message) {
        case WM_CREATE: 
            SetTimer(hwnd, ID_TIMER, 1000, NULL);
            return (0); 

        case WM_SIZE: 
            cxClient = LOWORD(lParam); 
            cyClient = HIWORD(lParam); 
            return (0);
        
        case WM_TIMER: 
            MessageBeep(MB_ICONINFORMATION); 
            iColorIndex += 1; 
            iColorIndex = iColorIndex % 3;
            iFontIndex += 1; 
            iFontIndex = iFontIndex % 2;
            InvalidateRect(hwnd, NULL, TRUE);
            return (0);

        case WM_PAINT :
            hdc = BeginPaint (hwnd, &ps);
            SelectObject (hdc, GetStockObject (fonts[iFontIndex]));
            SetTextColor(hdc, colors[iColorIndex]);
            SetTextAlign(hdc, TA_CENTER); 
            TextOut(hdc, cxClient/2, cyClient/2, TEXT("Hello,GUI WORLD!"), lstrlen(TEXT("Hello,GUI World!"))); 
            EndPaint (hwnd, &ps);
            return (0);

        case WM_DESTROY :
            KillTimer (hwnd, ID_TIMER) ;
            PostQuitMessage (0) ;
            return (0);
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}