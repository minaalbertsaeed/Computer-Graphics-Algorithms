#ifndef EllipseAlgorithms
#define EllipseAlgorithms 

#include <windows.h>

void Draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c);

void DrawEllipseNaive(HDC hdc, int xc, int yc, int A, int B, COLORREF c);


/*
As (x, y) = (A * cos(theta), B * sin(theta)) 
and dtheta = 1/max of A,B
and we are drawing a full quadrant then theta's ranges from [0,pi/2]
*/
void DrawEllipsePolar(HDC hdc,int xc,int yc,int A,int B,COLORREF c);

void DrawEllipsePolarImproved(HDC hdc,int xc,int yc,int A,int B,COLORREF c);


#endif 
