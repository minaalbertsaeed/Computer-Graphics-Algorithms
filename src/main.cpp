#include <vector>
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

/* Includes */ #include <tchar.h>
#include <windows.h>
#include <wingdi.h>
#include <utility>
#include <vector>
#include <iostream>
// #include <cmath>
// #include "CircleAlgorithms/CircleAlgorithms.h"
// #include "EllipseAlgorithms/EllipseAlgorithms.h"
#include "LineAlgorithms/LineAlgorithms.h"
#include "FillingAlgorithms/FillingAlgorithms.h"
using std::pair , std::vector, std::endl, std::cout, std::make_pair;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[] = _T("Windows App");

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    HWND hwnd;        /* This is the handle for our window */
    MSG messages;     /* Here messages to the application are saved */
    WNDCLASSEX wincl; /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */
    wincl.style = CS_DBLCLKS;            /* Catch double-clicks */
    wincl.cbSize = sizeof(WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL; /* No menu */
    wincl.cbClsExtra = 0;      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx(&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd =
        CreateWindowEx(0,                           /* Extended possibilites for variation */
                       szClassName,                 /* Classname */
                       _T(" Template Windows App"), /* Title Text */
                       WS_OVERLAPPEDWINDOW,         /* default window */
                       CW_USEDEFAULT,               /* Windows decides the position */
                       CW_USEDEFAULT,               /* where the window ends up on the screen */ 
                       544,                         /* The programs width */
                       375,                         /* and height in pixels */
                       HWND_DESKTOP,                /* The window is a child-window to desktop */
                       NULL,                        /* No menu */
                       hThisInstance,               /* Program Instance handler */
                       NULL                         /* No Window Creation data */
                       );

    /* Make the window visible on the screen */
    ShowWindow(hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage(&messages, NULL, 0, 0)) {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    static int x, y;
    static int count = 0;
    static int length = 5;
    static vector<pair<int, int >> points ;
    static COLORREF c = RGB(255, 0,0 );
    switch (message) {

        case WM_LBUTTONDOWN: {
            hdc = GetDC(hwnd);
            x = LOWORD(lParam);
            y = HIWORD(lParam);
            points.emplace_back(make_pair(x, y));

            if (count  == length - 1) {
                for (size_t i = 0; i < length;  i++) {
                    DrawLineDDA(hdc,  points[i].first ,  points[i].second,  points[(i + 1) % length].first,  points[(i + 1) % length].second, c);
                }

                count = 0;
                points.clear() ;
            }      
            else count++;
            
            ReleaseDC(hwnd, hdc);
            break;
        }

        case WM_RBUTTONDOWN:  {    // Release of left click
            hdc = GetDC(hwnd);
            COLORREF fc = RGB(0, 0,0 );
            int x1 = LOWORD(lParam);
            int y1 = HIWORD(lParam);
            MyFloodFill(hdc, x1, y1, c, fc );
            ReleaseDC(hwnd, hdc);
            break;
        }
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
