#ifndef LineAlgorithms
#define LineAlgorithms

#include <windows.h>

void Draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);

// Using the Cartesian Equation of Circle --> (x^2 + y^2 = R^2)
void DrawCircleCartesian(HDC hdc, int xc, int yc, int R, COLORREF c);

// Using the Polar Form as
// dtheta = 1/R
// x = R*cos(theta)
// y = R*sin(theta)
void DrawCirclePolarNaive(HDC hdc, int xc, int yc, int R, COLORREF c);

void DrawCirclePolarIterative(HDC hdc, int xc, int yc, int R, COLORREF c);

// void DrawCircleBresenham(HDC hdc, int x1, int y1, COLORREF color);

#endif 
