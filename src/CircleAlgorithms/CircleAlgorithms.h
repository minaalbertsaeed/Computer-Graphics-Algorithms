#ifndef CircleAlgorithms
#define CircleAlgorithms 

#include <windows.h>

void Draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);

// Using the Cartesian Equation of Circle --> (x^2 + y^2 = R^2)
void DrawCircleCartesian(HDC hdc, int xc, int yc, int R, COLORREF c);

// Using the Polar Form as
// dtheta = 1/R
// x = R*cos(theta)
// y = R*sin(theta)
void DrawCirclePolarNaive(HDC hdc, int xc, int yc, int R, COLORREF c);
/*
As x = R*cos(theta) 
y = R*sin(theta)
We start from the 1st octant x = R, y = 
then, new_x = R*cos(theta - dtheta) -- As x decreases
then, new_y = R*sin(theta + dtheta) -- As y increases
using the sum and diff trig identities 
--> new_x = R*Cos(theta) * cos(dtheta) - R*sin(theta) * sin(dtheta)
          = x * cos(dtheta) - y * sin(dtheta)

--> new_y = R*Cos(theta) * sin(dtheta) - R*sin(theta) * cos(dtheta)
          = x * sin(dtheta) - y * cos(dtheta)
 */
void DrawCirclePolarImproved(HDC hdc, int xc, int yc, int R, COLORREF c);

/* Based on the 1st Order Difference */
void DrawCircleBresenham1(HDC hdc, int x1, int y1, int R, COLORREF color);

/* Based on the 2nd Order Difference */
void DrawCircleBresenham2(HDC hdc, int x1, int y1, int R, COLORREF color);

#endif 
