#include "CircleAlgorithms.h"
// #include "LineAlgorithms.h"
#include <cmath>
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

void Draw8Points(HDC hdc, int xc, int yc, int x, int y, COLORREF c){
    SetPixel(hdc, xc+x, yc+y, c);
    SetPixel(hdc, xc-x, yc+y, c);
    SetPixel(hdc, xc-x, yc-y, c);
    SetPixel(hdc, xc+x, yc-y, c);

    SetPixel(hdc, xc+y, yc+x, c);
    SetPixel(hdc, xc-y, yc+x, c);
    SetPixel(hdc, xc-y, yc-x, c);
    SetPixel(hdc, xc+y, yc-x, c);
}

void DrawCircleCartesian(HDC hdc, int xc, int yc, int R, COLORREF c){
    int x = 0, y = R;
    Draw8Points(hdc, xc, yc, x, y, c);
    while (x < y) {
        x++;
        y = sqrt((double)R*R - x * x);
        Draw8Points(hdc, xc, yc, x, Round(y), c);
    }
}


void DrawCirclePolarNaive(HDC hdc, int xc, int yc, int R, COLORREF c){
    int x = R, y = 0;
    Draw8Points(hdc, xc, yc, x, y, c);
    double theta = 0, dtheta = 1.0/R;
    while (x > y) {
        theta += dtheta;
        x = Round(R * cos(theta));
        y = Round(R * sin(theta));
        Draw8Points(hdc, xc, yc, x, y, c);
    }
}

void DrawCirclePolarImproved(HDC hdc, int xc, int yc, int R, COLORREF c) {
    double x = R, y = 0;
    Draw8Points(hdc, xc, yc, x, y, c);
    double dtheta = 1.0/R;
    double changeInCos = cos(dtheta);
    double changeInSin = sin(dtheta);
    while (x > y) {
        double temp = x * changeInCos - y * changeInSin;
        y = x * changeInSin + y * changeInCos;
        x = temp;
        Draw8Points(hdc, xc, yc, x, y, c);
    }

}
