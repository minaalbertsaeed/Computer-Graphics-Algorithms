#include "EllipseAlgorithms.h"
#include <cmath>
#include <math.h>
#include <windows.h>
#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int Round(double x) {
	return (int)(x + 0.5);
}

void Draw4Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c){
    SetPixel(hdc, xc+x, yc+y, c);
    SetPixel(hdc, xc-x, yc+y, c);
    SetPixel(hdc, xc-x, yc-y, c);
    SetPixel(hdc, xc+x, yc-y, c);
}

void DrawEllipseNaive(HDC hdc, int xc, int yc, int A, int B, COLORREF c){
    double x = 0, y = B;
    double A2 = A * A;
    double B2 = B * B;
    
    // Region 1 
    // Calculate the slope where region 1, 2 meets which is dy/dx = -1
    // Differentiate the ellipse equation both sides with respect to x
    // and substitute with the dy/dx 
    // the final equation will be --> x * B^2 = y * A^2
    while (x * B2 <= y * A2) {
        Draw4Points(hdc, xc, yc, x, y, c);
        x++;
        y = sqrt(B2 * (1 - (x * x) / A2));
    }
    
    // Region 2
    while (y >= 0) {
        Draw4Points(hdc, xc, yc, x, y, c);
        y--;
        x = sqrt(A2 * (1 - (y * y) / B2));
    }
}

