#include <Windows.h> 
#include <stdio.h> 
#include <string.h> 

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window"); 
    static TCHAR szTitleOfWindow[] = TEXT("Hello,Win!"); 

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

    if(!RegisterClassEx(&wnd))
    {
        MessageBox(NULL, TEXT("Failed to register a window class"), TEXT("RegsiterClassEx"), 
                    MB_ICONERROR | MB_TOPMOST); 
        ExitProcess(EXIT_FAILURE); 
    }

    hwnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szTitleOfWindow, WS_OVERLAPPEDWINDOW, 
                            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                            NULL, NULL, hInstance, NULL); 
    if(hwnd == NULL)
    {
        MessageBox(NULL, TEXT("Failed to create a window"), TEXT("CreateWindowEx"), 
                    MB_ICONERROR | MB_TOPMOST); 
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
/*
CreateWindowEX "sends" WM_CREATE (often first message in queue of any window)
UpdateWindow sends WM_PAINT

ShowWindow api sends WM_SIZE, but then size is set to width and height passed in createWindowEx 
and same size is fetched in cxClient and cyClient. WM_PAINT uses these variables to align string at centre of window. 

Post that, whenever window is resized with "hardware interaction", 
event WM_SIZE is "posted", size of window is stored in cxClient & cyClient 
& WM_PAINT uses updated window size to align string at the centre of the window. So WM_PAINT becomes dependent on WM_SIZE 
whenever text is be to aligned at the centre of the window. Which is why WM_SIZE is triggered every time window is resized 
So that WM_PAINT can align string at the centre.

(Remember: Sent messages are generated by apis only. Posted messages are generated by api as well as hardware)
*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    /*
     * Latest State of window dimensions, should be persisted across WndProc calls 
     * Hence these variables are kept static
    */
    static int cxClient, cyClient; 

    HDC hdc; 
    PAINTSTRUCT ps; 

    switch(uMsg)
    {   
        case WM_PAINT: 
            hdc = BeginPaint(hwnd, &ps); 
            /*Align the text at the centre*/
            SetTextAlign(hdc, TA_CENTER); 
            TextOut(hdc, cxClient/2, cyClient/2, TEXT("Hello,GUI WORLD!"), lstrlen(TEXT("Hello,GUI World!"))); 
            EndPaint(hwnd, &ps); 
            break; 

        case WM_SIZE: 
            cxClient = LOWORD(lParam); 
            cyClient = HIWORD(lParam); 
            break; 

        case WM_DESTROY: 
            PostQuitMessage(0); 
            break; 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
}