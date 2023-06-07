/*
	@goal: To write a program to create a window using win api and build understanding of event queues. 
	@author: Abhijeet Rai 
	@date: 26-05-2023
*/

#include <Windows.h> 

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

/*
 * Every exe wich renders GUI, may (or may not) have multiple windows to show or render. 
 * Each window has an event queue associated to it. (PS: This program will render only one window)
 * WndProc is a callback function (called by OS) to process or to fulfil each message/event on the message/event queue. 
 * hwnd: Handle to the window whose event is being processed 
 * uMsg: The event or the message itself, example: WM_CREATE, WM_PAINT, WM_SIZE, where WM stands for windows message. 
 * wParam & lParam: When WndProc processes an event, info about the event is stored in wParam & lParam. Hence meaning of 
 *					lParam and wParam varies from message to message. In case of WM_SIZE event (whenever the window is resized)
 					lower four bytes of lParam have width of the window and upper four bytes have height of the window   
*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 


/*
 * hInstance: Handle to the current exe of program
 * hPrevInstance: Handle to the previous exe of program 
 				  In older version of windows, if multiple instances of an app were open. 
 				  And we tried to maximize an instance, the other instance used to be minimised 
 * lpCmdLine: Address of the command used to run the program 
 * nShowCmd: Default window size, after program opens
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	/* 
	 * If we are using UNICODE(#define UNICODE) to store characters, char type takes 2 bytes otherwise it takes 1 bytes of space in memory 
	 * type TCHAR has been typedef(ed) to use 2 bytes if unicode is defined or 1 byte, if it has not been defined.
	 * TEXT macro identifies a string as UNICODE, when UNICODE is defined by a preprocessor directive. Otherwise it identifies string as ANSI
	*/
	static TCHAR szClassName[] = TEXT("The Standard Window");
	static TCHAR title[] = TEXT("Hello Windows!");

	HWND hwnd = NULL; 
	WNDCLASSEX wnd; 
	MSG msg; 

	ZeroMemory(&wnd, sizeof(WNDCLASSEX));
	ZeroMemory(&msg, sizeof(MSG));

	/*Size of strucutre in bytes*/
	wnd.cbSize = sizeof(WNDCLASSEX);
	
	/*Any extra bytes for the window class(rarely set to non zero)*/
	wnd.cbClsExtra = 0;
	
	/*Any extra bytes for the window, which will be created in our program(rarely set to non zero)*/
	wnd.cbWndExtra = 0;
	
	/*GetStockObject returns(HGDIOBJ) Handle to graphics device interface object, hence we cast return to HBRUSH*/
	/*Will see more on device context, down the line*/
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	
	/*
	 * NULL: A handle to an instance of the module whose executable file contains the cursor to be loaded.
	 		 Here, NULL means calling module, which is our program's exe 
	   IDC_ARROW: is the type or name of the cursor, other options could be IDC_HAND, IDC_WAIT
	*/
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	
	/*NULL: the calling module, IDI_APPLICATION: name of icon which we will see when window opens*/
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	
	/*NULL: the calling module, IDI_APPLICATION: icon of exe file visible in the explorer*/
	wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	
	/*handle to the instance, which contains the window procedure*/
	wnd.hInstance = hInstance;
	
	/* Does this line need explaination at this point now? Windows os will call callback function WndProc
	 * But windows needs to store the address of this procedure somewhere, right? Hence we are storing address 
	 * of WndProc in structure instance of WNDCLASSEX and will register window with this instance, (will give this instance to OS)
	*/	
	wnd.lpfnWndProc = WndProc;

	/*
	 * It is like fetching a window based on its type, pretty much like factory pattern
	 * (Custom windows can also be registered in win api and then fetched ?)
	*/
	wnd.lpszClassName = szClassName;
	/*
	 * The window which we will render, has no Menu bar, hence this field is NULL
	*/
	wnd.lpszMenuName = NULL;

	/*
	 * Because of bitwise OR (|), both the options are simultaenously selected. 
	 * These bitflags notify OS about the event of horizontal or vertical resizing of the created window.
	 * OS then adjusts the content painted on the window, if the window is horizontally or vertically resized 
	 * CS_HREDRAW: CS stands for class style, HREDRAW notifies OS about the horizontal resizing of the created window 
	 * CS_VREDRAW: CS stands for class style, VREDRAW notifies OS about the vertical resizing of the created window
	*/
	wnd.style = CS_HREDRAW | CS_VREDRAW;

	
	/* Returns 0, if the window could not be registered */
	if(!RegisterClassEx(&wnd)) {
		/*First argument to MessageBox is handle to owner window of message box, if NULL, then there is no owner window*/
		MessageBox(NULL, TEXT("Failed to register window class"), TEXT("RegisterClassEx"), MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);
	}


	/*
	 * WS_EX_APPWINDOW: is the extended window style, it forces created window's icon on taskbar's first row, 
	 					even if taskbar has fallen short of space, (probably by pushing other icon in second row)
	 * szClassName: Type of the window class, we will use to create window. Window class can be inbuilt or custom registerd by the user 
	   				(The task of creating window occurs in stages: Stage 1 is filling & registering wnd, and other stage is actually creating 
	   				using CreateWindowEx 
     * title: Content of the title bar
     * WS_OVERLAPPEDWINDOW: Style of the window to be created, combination of 6 window styles: WS_CAPTION, WS_THICKFRAME, WS_MINIMIZEBOX 
     						WS_MAXIMIZEBOX, WS_SYSMENU, WS_OVERLAPPED(allows our windows to get overlapped). Read about other flags in the winapi doc
     * CW_USEDEFAULT: CW stands for create window, x cordinate of left top most corner of the window to be created.
     * CW_USEDEFAULT: y cordinate of left top most corner of the window to be created.
     * CW_USEDEFAULT: width of the window to be created
     * CW_USEDEFAULT: height of the window to be created 

     * ALL THESE VALUES ARE NOT HARDCODED, BECAUSE WE DO NOT KNOW YET, WHAT KIND, SIZE, RESOLUTION OF DISPLAY OR SCREEN WILL BE USED 
     * TO SHOW THE WINDOW, AND WE CANNOT YET GUESS, WIDTH AND HEIGHT. OS, ON THE OTHER HAND, HAS CONTEXT(IDEA) OF THE OUTPUT DEVICE,
     * HENCE IT ALLOCATES APPROPIRATE POSITION AND DIMENSIONS TO THE WINDOW TO BE CREATED

     * NULL: Handle to the parent window of window to be created. If set NULL, desktop acts as parent window 
     * NULL: hMenu, handle to menu bar. Single window which will be created from our side has no menu bar, hence it is set to NULL 
     * hInstance: A handle to the instance of the module to be associated with the window
     * NULL: lParam: LPVOID: CreateWindowEx "sends" event WM_CREATE to event_queue of application. If we want, while sending message WM_CREATE
     						 it should deliver some data to application. That data is lParam (void* to be compatible to all types)
	*/

	/*	
	 * CONCEPT OF POST MESSAGE VS SEND MESSAGE:
	 ------------------------------------------
	 ------------------------------------------
	 * As we know, every window has an event queue associated with it. An event is generated by hardware interaction or apis and go and 
	 * falls on the end of queue. For every message, WndProc is called and it processes every message. Every message is processed one by one 
	 * This is the ususal behaviour of POSTED MESSAGEs. 

	 * Some apis do not only generate messages, but also call WndProc for that message instantly to process or fulfil that message
	 * Regardless how many events are already waiting in the queue or what WndProc call is currently active or in execution. 
	 * These are called SENT MESSAGEs. 
	 * CreateWindowEx sends message WM_CREATE.
	*/

	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                            NULL, NULL, hInstance, NULL);
	if(hwnd == NULL) {
        MessageBox(NULL, TEXT("Failed to create a window!"),TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);
    }

    /*
     * This function controls, how window will be shown on the screen
     * hwnd: Handle to the window, which we want to show 
     * nShowCmd: Please show window as in(dimension and position wise), as mentioned in CreateWindowEx
    */
    ShowWindow(hwnd, nShowCmd);

    /*
     * Window is actually show or painted, when UpdateWindow is called 
     * It sends message WM_PAINT to event queue
    */
    UpdateWindow(hwnd);

    
    /*
    * All the parts related to window creation are completed now
    * Whatever happens next, is mainly event driven. Application is blocked (waiting) for events.
    * Program will now read event queue, put each event in msg instance, on by one
    * and process it (call WndProc for each event)

		typedef struct tagMSG {
		    HWND        hwnd;		Handle to the window, to which event belongs (A program has multiple windows and windows have respective event queue)
		    UINT        message;	The event itself
		    WPARAM      wParam;		Data
		    LPARAM      lParam;		Data
		    DWORD       time;		Timestamp of event
		    POINT       pt;			Mouse cordinate of event (applicable in case of hardware interaction of mouse)
		}msg;
    */


    /*
     * GetMessage keeps waiting for an event to be delivered, if event queue is empty. 
     * And if event queue is not empty, take events one by one, paste contents of events into &msg we pass and process. 
     * (And then delete currently processed event)
     
     * NULL: Handle to window, whose events we want to fetch. Since our program will render one window only, setting it to NULL 
     		 by default makes it to point to that one window we will create
     * 0: Lower limit of event range to be fetched from event queue  
     * 0: Higher limit of event range to be fetched from event queue
     * Set 0, 0 to fetch the events in the order they are queued
    */ 
    while(GetMessage(&msg, NULL, 0, 0)) {
    	TranslateMessage(&msg);
    	/*
    	 * DispatchMessage triggers OS to call callback function WndProc (from kernel stack)
    	 * pWnd->lpfnWndProc(pMsg->hwnd, pMsg->uMsg, pMsg->wParam, pMsg->lParam)
    	*/ 
    	DispatchMessage(&msg);
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
     * Applicable on all those events, which are not handled in the switch above
     * For example: as we press on close button, WM_CLOSE event is added to the queue 
     * It is not handled in switch above, hence it will be addressed here, event WM_CLOSE is addressed here as of now 
     * WM_CLOSE event puts WM_DESTROY on the event queue 
    */
    return (DefWindowProc(hwnd, uMsg, wParam, lParam));
}