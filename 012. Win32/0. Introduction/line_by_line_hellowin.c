/**
 * Taught in MSTC-3 (Sep 20, 2022- Sep 20, 2023)
 * SESSION: 69, 70, 72, 72
*/

#include <Windows.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

//mostly callback functions event handlers event hone pe call karte hai 
//hwnd: kaunsa window ke events capture hue is, us window ka handle is pointed by hwnd, read line 161 for clarity
//uMsg: event no hai, kaunse event ko process karne ise call kia hai
//wParam, lParam kernel ko koi message bhejna hoga uske lie use hoga realted to event, additional info about event
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//Ye program ka exe run kia, ye ek event hai, exe ram me gai, event hai. 
//Event handler resource tayar karega instance tpye ka, callback function winmain call karega

//hinstance: handler to this program ka instance 
//lpCmdLine: address of command used to run the program 
//nShowCmd: default window size, after program opens
//hprevInstance: handler ot previous instance of program, null nowdays 
//but in basic version of windows, when two windows of same app used to be opened, 
//first used to minimised due to ram shortage
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine, int nShowCmd) 
{
    //agar #define UNICODE kia to TCHAR 2 byte ka typedef hoga otherwise 1 byte
    //for ascii 1 byte, islie TCHAR use karo, jo apna size flexibly unicode ya ascii dekh ke
    //apne aap ghat-ata badh-ata hai
    //TEXT: Identifies a string as Unicode when UNICODE is defined by a preprocessor directive during compilation.
    // Otherwise, the macro identifies a string as an ANSI string
    //keep it to identify string as unicde apne aap, when unicode will be defined using #define UNICODE
    static TCHAR szClassName[] = TEXT("The Standard Window");
    static TCHAR title[] = TEXT("Hello Windows!");

    HWND hwnd = NULL; 
    WNDCLASSEX wnd; 
    MSG msg; 

    ZeroMemory(&wnd, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    //size of structure depends on 32 but or 64 bit system and will be calculated on run time
    wnd.cbSize = sizeof(WNDCLASSEX);  //cb = count bytes
    wnd.cbClsExtra = 0; //if extra byte is needed for window class
    wnd.cbWndExtra = 0; //if extra byte is needed for actual window here, which is to be created, prepared from window class on previous line
    
    //GetStockObject can return many things, hence its return type is HGDIOBJ: handle to graphics device interface object
    //GDI object is common object to graphics programming
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    
    //LoadCursorW(_In_opt_ HINSTANCE hInstance, _In_ LPCWSTR lpCursorName);
    //Each module used in the process exists in virtual address space of process
    //Each module (library) has (text, bss, data, rodata section) in its own right
    //hInstance is handle to resource of type module 
    //Here hInstance near line 56 accpets which module will contain created load cursor, 
    //here NULL means calling module (that is our program exe)
    //IDC_ARROW is the name of cursor
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);      
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);        //icon is exe open karne ke bad dikhne wala icon window pe
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);      //handle to small icon, small icon is exe icon when it is kept as file in folder
    wnd.hInstance = hInstance;                          //handle to instance that contains window procedure(current exe ka handle)
    wnd.lpfnWndProc = WndProc;                          //handle to window procedure
    
    //Fetching a type of window based on its name, pretty much like factory pattern
    wnd.lpszClassName = szClassName;                    
    //There is no menu bar in our window, which is to be created
    wnd.lpszMenuName = NULL; 
    //Because of bitwise OR (|), both the options are simultaneously selected
    //If user decides to readjust window width or height, OS traps the event and notifies program
    //OS notifies the program current width and current height and program adjusts the content on window
    //CS_HREDRAW notfies about horizonal adjustment of window size event 
    //CS_VREDRAW notifies about veritcal adjustment of window size event
    //CS_HREDRAW and CS_VREDRAW are bit flag
    wnd.style = CS_HREDRAW | CS_VREDRAW;            //CS stands for class style


    if(!RegisterClassEx(&wnd)) {
        MessageBox(NULL, TEXT("Failed to register window class"), TEXT("RegisterClassEx"), MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);
    }

    /*
     * WS_EX_APPWINDOW: Extended Window Style: When too many apps are open if task bar has fallen short of space, 
                        Then horizontal scroll bar is crated on taskbar to accomodate all app window icons on the taskbar 
                        Extened Window style: WS_EX_APPWINDOW, forces created window icon in the first row of taskbar (even if it needs to move other icon to second row)
                        Forces the created window icon onto the taskbar when the window is visible.

        szClassName:    Type of window class, we want to use to create window. Window class can be in-built or custom registered by user
        title:          Content of created window title bar
        
        WS_OVERLAPPEDWINDOW:    Style of windows to be created, it is bitwise or of 6 windows styles   
                                WS_CAPTION: title bar is visible because of this style
                                WS_THICKFRAME: resize border visible
                                WS_MINIMIZEBOX: minimize button visible on title bar
                                WS_MAXIMIZEBOX: maximize button visible on title bar
                                WS_SYSMENU: close button visible on title bar and menu visible after clicking on on left most small app icon on title bar
                                WS_OVERLAPPED: Give pemission, my created window is gonna get overlapped by other window.  

        Position and dimensions off the created window in next 4 parameters
        CW_USEDEFAULT: x: x cordinate of left top most corner of windows to be created on the screen
        CW_USEDEFAULT: y: y cordinate of left top most corner of windows to be created on the screen
        (x, y) is position of the left most corner of the windows to be created on the screen
        CW_USEDEFAULT: nwidth: width of the windows to be created 
        CW_USEDEFAULT: nheight: height of the windows to be created

        WE AVOIDED SETTING HARDOCDED VALUES, BECAUSE WE DO NOT KNOW, WHERE OUR CODE WILL RUN ON WHAT TYPE OF SCREEN RESOLUTION
        WHEN SET CW_USEDEFAULT WINDOWS MANAGER TAKES OVERHEAD TO POSITION CREATED WINDOW AT APPROPIRATE POSITION WITH APPROPIRATE SIZE ON ALL TYPES OF SCREEN

        NULL: hWndParent: Parent window of the window to be created. When set null, desktop is parent window
        NULL: hMenu: Our windows, which has to be created has no menu, hence it is set to null
        hInstance: hInstance: A handle to the instance of the module to be associated with the window.
        
        NULL: lpParam: OS traps events and call callback functions. But it is not necessary, only end user is not responsible for creating event.
                        Some events are created by programming functions. When windows is created using createwindowex, it is also an event.
                        When window is created in memory and before its handle is returned. CreateWindowEx generates event WM_CREATE & delivers event to application. 
                        When that event is processed, then handle is returned. 

                        If we want to customise that when CreateWindowEx generates event WM_CREATE and delivers it to application. Then while doing it, it should also 
                        deliver data to the application, that data is lParam. Data type should be compatible to all, hence type here is void*

                        WM_CREATE is sent message
    */
    hwnd = CreateWindowEx(WS_EX_APPWINDOW, 
                            szClassName, 
                            title, 
                            WS_OVERLAPPEDWINDOW, 
                            CW_USEDEFAULT,              //CW stands for CreateWindow
                            CW_USEDEFAULT, 
                            CW_USEDEFAULT,
                            CW_USEDEFAULT, 
                            NULL, 
                            NULL,
                            hInstance, 
                            NULL
                        );

    if(hwnd == NULL) {
        MessageBox(NULL, TEXT("Failed to create a window!"),
                        TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);
    }

    /**
     * ShowWindow controls how created window will be shown on screen
     * hwnd: handle to window, which we want to show
     * nShowCmd: please show the window as is(dimension and position wise), as described in CreateWindowEx  
    */
    ShowWindow(hwnd, nShowCmd);
    

    /**
     * MESSAGES WHICH ARE GENERATED BY H/W INTERACTION OR APIS AND GO ON MESSAGE QUEUE TO BE PROCESSED BY GETMESSAGE ARE CALLED AS POSTED MESSAGES
     * SOME WIN32 APIs, not only generate message, but also calls wndproc immediatly themselves to process the message, it is called sent message
    */
    /*
     * As soon as UpdateWindow is called, an event is delivered to the application 
     * that please start painting client area of the window. It is sent message, WM_PAINT.
     * It calls WndProc to process message WM_PAINT immediately
    */
    UpdateWindow(hwnd);         
    /*Once these methods are called, then windows is shown on screen
    * Window creation part is over here at the call of UpdateWindow, whatever happens next is totally driven by events
    * Applications keeps waiting (blocked) for events to happen
    */


    /**
     * Every GUI application has an event queue, where events are delivered and then processed 
     * EVERY WINDOW, THAT AN APPLICATION CREATES, HAS ITS OWN MESSAGE QUEQUE. (In our case, this application or program has only one window)
            typedef struct tagMSG {
                HWND        hwnd;           helps to identify which window's (of which app) events to be captured
                UINT        message;        what event has occured on window pointed by hwnd
                WPARAM      wParam;         Depending on event type, data regarding event is collected  (If window is resized, new dimension is stored in data)
                LPARAM      lParam;         Depending on event type, data regarding event is collected  (If window is resized, new dimension is stored in data)
                DWORD       time;
                POINT       pt;
            }MSG;
     * 
     * Interaction of the end user with application is trapped by the OS as HardWare event
     * ALSO SOME APIS, also add events to event queues
    */

    /**
     * MESSAGES WHICH ARE GENERATED BY H/W INTERACTION OR APIS, AND GO ON MESSAGE QUEUE TO BE PROCESSED 1 by 1, BY GETMESSAGE ARE CALLED AS POSTED MESSAGES
     * SOME WIN32 APIs, not only generate message, but also call wndproc immediatly themselves to process the message, it is called sent message
    */


    /*
     * GetMessage: If the event queue is empty then block until it becomes nonempty at least till one pending event
     *             If the event queue is not empty, take the first event on the event queue, copy paste its contents into msg instance provided my programmer
     *             Removes the copy of MSG in event queue (because it is processed)
     * 
     * NULL: hwnd: Which window ka, event queue ka message is required, us window ka handle, but our program has one window only, hence NULL is sent. 
     *          Then, By default that window's event queue, events will be fetched.
     * 0: UINT: lower limit of event range to be fetched from event queue
     * 0: UINT: higher limit of event range to be fetched from event queue
     * Set 0, 0 to fetch all events
    */
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);    
        /**
         * DispatchMessage EVENTUALLY calls WndProc. WndProc is called by OS, it is callback function
         */    
        DispatchMessage(&msg);      
        /*
         pWnd->lpfnWndProc(pMsg->hwnd, pMsg->uMsg, pMsg->wParam, pMsg->lParam)
        */
    }

    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { 

    static int cxScreen, cyScreen; 
    static TCHAR szPrompt[] = TEXT("ABHIJEET RAI - ROLL NUMBER: 154 - CPA MSTC 3");
    int iLen; 

    HDC hdc = NULL; 
    PAINTSTRUCT ps; 

    switch(uMsg) {
        case WM_SIZE: 
            cxScreen = LOWORD(lParam); 
            cyScreen = HIWORD(lParam); 
            return (0);

        case WM_PAINT: 
            hdc = BeginPaint(hwnd, &ps);
            iLen = lstrlen(szPrompt);
            SetTextAlign(hdc, TA_CENTER);
            TextOut(hdc, cxScreen/2, cyScreen/2, szPrompt, iLen);
            EndPaint(hwnd, &ps);
            return (0);

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            /**
             * PostQuitMessage projects event WM_QUIT on event queue
             * WM_QUIT event returns 0 to GetMessage
            */
            return (0);
    }
    /**
     * Applicable on all those events, which are not handled in switch
     * For example: as we press on close button, WM_CLOSE event is added to the queue 
     * It is not handled in switch above, hence it will be addressed here, event WM_CLOSE is addressed here as of now 
     * WM_CLOSE event puts WM_DESTROY on the event queue 
    */
    return (DefWindowProc(hwnd, uMsg, wParam, lParam));
}

/*
Sir, we have attended all Win32 lectures, read notes and listened to recordings. 
Have understood all concepts, functions(& respective parameters), event queues. 

Sorry, But there is some difficulty to recall last 10-15 percent, apologies if you 
want, could you please, help us to a bit to recall or revise following concepts out of middle 

1. SentMessage vs PostMessage, how they came into context of our code (cannot recall that part)
2. Explain the case WM_SIZE: and case WM_PAINT code & syntax. 
3. What exists or significance in the msg.wParam at the end of code: 
    return (msg.wParam) in WinMain after PostQuitMessage has put 0 to GetMessage call 
4. Return type of both functions
*/ 

/*
Sir we took a combination of cases previously 
Is it possible to :Call functions from A to B. Return values from A to B 

When A & B could be User stack-user stack. User stack-Kernel Stack. Kernel stack-user stack.
Can we revise this in tabular form
*/