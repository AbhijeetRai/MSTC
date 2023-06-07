/*
The graphics card and monitor roughly make the graphics device. 
Windows API provides an interface to interact with the graphics device. 

According to the wikipedia:
    The Graphics Device Interface (GDI) is a legacy component of Microsoft Windows responsible for representing graphical objects 
    and transmitting them to output devices such as monitors and printers

Remember: GetStockObject returns HDIOBJ, which is handle to graphics device interface object. 
        Handle to such an object which allows us to interact (interface) with the graphics device.

While creating window, we gave left top most (x, y) co-ordiante of the window to be created. 
We passed width and height of the window to be created. But we did not hard code these values. 
Instead we passed CW_USEDEFAULT for all parameters mentioned above. Why? Because, we did not 
know anything about display or screen resolution where window will be created. 

We said let's use CW_USEDEFAULT and os will appropirately place left top most corner with adequate height and width of the window. 
Since OS has idea (context) of the output device. Device context: is the information which OS stores about the device monitor.

The device context is used to: 
    i)  Paint the window
    ii) Get & Set properties of device context, which change look and feel of content painted on the window
*/

/*
The 2 ways to get device context is shown as below. 
Freeing the resource:
    When we GetDC in WM_CREATE, an instance of resource is created on the heap
    & if we forget to release the DC. DC instance will exist on the heap as is. 
    WndProc will be called for next event, (assume it is) WM_CREATE again,
    DC will be created on the heap again and it will be left there. 
    Creating the same resource, everytime the event occurs. 
    At some point, heap will run out of memory leading to exe crash 
    Hence it is a good idea to ReleaseDC (release the created resources).

    Remember when we lost address of dynamically mapped memory, we called it memory leak 
    Is something similar happening here?
*/
#include <Windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch(uMsg) {
        HDC hdc;
        case WM_CREATE:
            /*is it like, get context of device, where this window is being shown or will be shown*/
            hdc = GetDC(hwnd); 
            ReleaseDC(hwnd, hdc); 
            break;
    }
}

/**
 * Textout(hdc, x, y, string_to_print, length_of_string_to_print): It is print of GUI 
 * It takes x, y to align the string or in short co-ordinates of string, with respect to the left top most corner of the window
*/

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    HDC hdc; 
    /*PAINTSTRUCT is like a bucket, which helps to paint*/
    PAINTSTRUCT ps; 

    switch(uMsg) {
        case WM_PAINT: 
            hdc = BeginPaint(hwnd, &ps);
            /*Do not worry about releasing DC here, EndPaint does that*/
            EndPaint(hwnd, &ps);
            break;
    }
}

