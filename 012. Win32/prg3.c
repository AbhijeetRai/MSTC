#include <Windows.h> 
#include <stdio.h> 
#include <string.h> 

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

    static TCHAR szClassName[] = TEXT("The Standard Window");
    static TCHAR szTitleOfWindow[] = TEXT("Hello, Win!");

    WNDCLASSEX wnd; 
    MSG msg; 
    HWND hwnd = NULL;

    ZeroMemory(&wnd, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.cbClsExtra = 0; 
    wnd.cbWndExtra = 0;
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hInstance = hInstance; 
    wnd.lpfnWndProc = WndProc;
    wnd.lpszClassName = szClassName;
    wnd.lpszMenuName = NULL; 
    wnd.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClassEx(&wnd)) {
        MessageBox(NULL, TEXT("Failed to register a window class"), TEXT("RegsiterClassEx"), MB_ICONERROR | MB_TOPMOST); 
        ExitProcess(EXIT_FAILURE); 
    }

    hwnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szTitleOfWindow, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                            NULL, NULL, hInstance, NULL);
	if(hwnd == NULL) {
        MessageBox(NULL, TEXT("Failed to create a window!"),TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);
    }

    ShowWindow(hwnd, nShowCmd); 
    UpdateWindow(hwnd); 

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }
    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    HDC hdc; 
    PAINTSTRUCT ps;

    switch(uMsg) {
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps); 
            TextOut(hdc, 0, 0, TEXT("Hello, GUI World!"), lstrlen("Hello, GUI World!"));
            EndPaint(hwnd, &ps);
            break; 

        case WM_DESTROY: 
            PostQuitMessage(0);
            break;
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam));
}