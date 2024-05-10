// #include <minwindef.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <tchar.h>
#include <GL/gl.h> 
#include <GL/glu.h>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

LRESULT WINAPI WndProc(HWND hwnd, UINT m, WPARAM wp, LPARAM lp)
{
	static PIXELFORMATDESCRIPTOR pfd = {
	sizeof(PIXELFORMATDESCRIPTOR),   // size of this pfd  
	1,                     // version number  
	PFD_DRAW_TO_WINDOW |   // support window  
	PFD_SUPPORT_OPENGL |   // support OpenGL  
	PFD_DOUBLEBUFFER,      // double buffered  
	PFD_TYPE_RGBA,         // RGBA type  
	24,                    // 24-bit color depth  
	0, 0, 0, 0, 0, 0,      // color bits ignored  
	0,                     // no alpha buffer  
	0,                     // shift bit ignored  
	0,                     // no accumulation buffer  
	0, 0, 0, 0,            // accum bits ignored  
	32,                    // 32-bit z-buffer  
	0,                     // no stencil buffer  
	0,                     // no auxiliary buffer  
	PFD_MAIN_PLANE,        // main layer  
	0,                     // reserved  
	0, 0, 0                // layer masks ignored  
	};

	static HDC hdc;
	static HGLRC hgl;
	static int w,h;
	static int count = 0;
	int  iPixelFormat;

    switch (m)
    {
    case WM_CREATE:
        hdc = GetDC(hwnd);
        iPixelFormat = ChoosePixelFormat(hdc, &pfd);
        SetPixelFormat(hdc, iPixelFormat, &pfd);
        hgl = wglCreateContext(hdc);
        wglMakeCurrent(hdc, hgl);
        glClearColor(0, 0, 0, 0);
        break;

    case WM_SIZE:
        w = LOWORD(lp);
        h = HIWORD(lp);
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        break;

    case WM_LBUTTONDOWN: {
        // Draw 3D Scene
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        // Draw building
        glColor3f(0.5f, 0.5f, 0.5f); // Gray building color
        glBegin(GL_QUADS);
        // Front face
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 2.0f, 1.0f);
        glVertex3f(-1.0f, 2.0f, 1.0f);
        // Back face
        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-1.0f, 2.0f, -1.0f);
        glVertex3f(1.0f, 2.0f, -1.0f);
        glVertex3f(1.0f, 0.0f, -1.0f);
        // Right face
        glVertex3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, 2.0f, 1.0f);
        glVertex3f(1.0f, 2.0f, -1.0f);
        glVertex3f(1.0f, 0.0f, -1.0f);
        // Left face
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-1.0f, 2.0f, -1.0f);
        glVertex3f(-1.0f, 2.0f, 1.0f);
        glEnd();

        // Draw roof
        glColor3f(0.8f, 0.4f, 0.1f); // Brown roof color
        glBegin(GL_TRIANGLES);
        glVertex3f(-1.0f, 2.0f, 1.0f);
        glVertex3f(1.0f, 2.0f, 1.0f);
        glVertex3f(0.0f, 3.5f, 0.0f);
        glEnd();

        // Draw door
        glColor3f(0.2f, 0.2f, 0.2f); // Dark gray door color
        glBegin(GL_QUADS);
        glVertex3f(-0.3f, 0.0f, 1.01f);
        glVertex3f(0.3f, 0.0f, 1.01f);
        glVertex3f(0.3f, 1.0f, 1.01f);
        glVertex3f(-0.3f, 1.0f, 1.01f);
        glEnd();

        // Draw windows
        glColor3f(0.5f, 0.8f, 1.0f); // Light blue window color
        glBegin(GL_QUADS);
        // Window 1
        glVertex3f(-0.8f, 1.5f, 1.01f);
        glVertex3f(-0.6f, 1.5f, 1.01f);
        glVertex3f(-0.6f, 1.8f, 1.01f);
        glVertex3f(-0.8f, 1.8f, 1.01f);
        // Window 2
        glVertex3f(0.6f, 1.5f, 1.01f);
        glVertex3f(0.8f, 1.5f, 1.01f);
        glVertex3f(0.8f, 1.8f, 1.01f);
        glVertex3f(0.6f, 1.8f, 1.01f);
        glEnd();
        // Window 3
        glVertex3f(-0.8f, 0.2f, 1.01f);
        glVertex3f(-0.6f, 0.2f, 1.01f);
        glVertex3f(-0.6f, 0.5f, 1.01f);
        glVertex3f(-0.8f, 0.5f, 1.01f);
        // Window 4
        glVertex3f(0.6f, 0.2f, 1.01f);
        glVertex3f(0.8f, 0.2f, 1.01f);
        glVertex3f(0.8f, 0.5f, 1.01f);
        glVertex3f(0.6f, 0.5f, 1.01f);
        glEnd();

        glFlush();
        SwapBuffers(hdc);
        count = 0;
    }
    }
	return 0;

}

int APIENTRY WinMain(HINSTANCE hi, HINSTANCE pi, LPSTR c, int ns) {

	WNDCLASS wc;

	wc.cbClsExtra = 0;

	wc.cbWndExtra = 0;

	wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);

	wc.hInstance = hi;

	wc.lpfnWndProc = WndProc;

	wc.lpszClassName = "MyClass";

	wc.lpszMenuName = NULL;

	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	HWND hwnd = CreateWindow("MyClass", "Hello World", WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hi, 0);

	ShowWindow(hwnd, ns);

	UpdateWindow(hwnd);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0) > 0)

	{

		TranslateMessage(&msg);

		DispatchMessage(&msg);

	}

	return 0;

}


