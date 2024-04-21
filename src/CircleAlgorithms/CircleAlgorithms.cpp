#include "CircleAlgorithms.h"
// #include "LineAlgorithms.h"
#include <cmath>
#include <windows.h>
#include <iostream>

using std::cos, std::sin, std::sqrt;

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

void DrawCircleBresenham1(HDC hdc, int xc, int yc, int R, COLORREF c) {
    int x = 0 ,y = R;
    Draw8Points(hdc, xc, yc, x, y, c);
    int  d = 1 - R;

    while (x < y) {
         if(d >= 0 ){
            d += 2*(x - y) + 5;
            y--;
        }else {
            d += (2 * x) + 3;
        }
        x++;
        Draw8Points(hdc, xc, yc, x, y, c);
    }

}


void DrawCircleBresenham2(HDC hdc, int xc, int yc, int R, COLORREF c) {
    int x = 0 ,y = R;
    Draw8Points(hdc, xc, yc, x, y, c);
    int d = 1 - R;
    int change1 = 3;
    int change2 = 5 - 2 * R;
    
    while (x < y) {
        if(d >= 0){
            d += change1;
            change2 += 2;
        }else {
            d+= change2; 
            change2 += 4;
            y--;
        }
         x++; change1 += 2;
        Draw8Points(hdc, xc, yc, x, y, c);
    }

}
