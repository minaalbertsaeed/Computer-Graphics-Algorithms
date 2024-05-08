#include "EllipseAlgorithms.h"
#include "windef.h"
#include <algorithm>
#include <cmath>
#include <windows.h>
#include <iostream>

using std::cos, std::sin, std::sqrt, std::max, std::cout;

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
    Draw4Points(hdc, xc, yc, x, y, c);
    while (x * B2 <= y * A2) {
        x++;
        y = sqrt(B2 * (1 - (x * x) / A2));
        Draw4Points(hdc, xc, yc, x, y, c);
    }
    
    // Region 2
    while (y >= 0) {
        y--;
        x = sqrt(A2 * (1 - (y * y) / B2));
        Draw4Points(hdc, xc, yc, x, y, c);
    }
}

void DrawEllipsePolar(HDC hdc,int xc,int yc,int A,int B,COLORREF c) {
    int x = A, y = 0;
    double dtheta = 1.0 / max(A,B);
    double HalfPI = M_PI / 2.0;

    Draw4Points(hdc, xc, yc, x, y, c);

    for(double theta = 0; theta < HalfPI; theta += dtheta) {
        x = A * cos(theta);
        y = B * sin(theta);
        Draw4Points(hdc, xc, yc, x, y, c);
    }
}


void DrawEllipsePolarImproved(HDC hdc, int xc, int yc, int A, int B,COLORREF c) {
    double x = 0, y = B;
    Draw4Points(hdc, xc, yc, x, y, c);
    double dtheta = 1.0 / max(A,B);
    double CosDtheta = cos(dtheta), SinDtheta = sin(dtheta);
    double AoverB = (double)A/B, BoverA = (double)B/A;

    double HalfPI = M_PI / 2.0;

    for(double theta = 0; theta < HalfPI; theta += dtheta) {
        double temp = (x * CosDtheta) - (AoverB * y * SinDtheta);
        y = (y * CosDtheta ) + (BoverA * x * SinDtheta);
        x = temp;
        Draw4Points(hdc, xc, yc, Round(x), Round(y), c);
    }
}

void DrawEllipseBresenham1(HDC hdc, int xc, int yc, int A, int B, COLORREF c) {
    double x = 0, y = B;
    int A2 = A * A;
    int B2 = B * B;
    Draw4Points(hdc, xc, yc, x, y, c);
    double d1 = B2 - B * A2;

    while (x * B2 < y * A2) {
        if (d1 >= 0) {
            d1 += B2 * (2 * x + 3) +  A2 * (-2 * y + 2 );
            y--;
        }
        else
            d1 += B2 * (2 * x + 3);
        
        x++;
        Draw4Points(hdc, xc, yc, Round(x), Round(y), c);
    }

    x = A, y = 0;
    double d2 = A2 - (A * B2);
    while (x * B2 > y * A2) {
        if (d2 >= 0) {
            d2 += (-2 * x * B2) + (2 * B2) + (2 * y * A2) + (3 * A2) ;
            x--;
        }
        else
            d2 += (2 * y * A2) + (3 * A2);
        
        y++;
        
        Draw4Points(hdc, xc, yc, Round(x), Round(y), c);
    }

}

void DrawEllipseBresenham2(HDC hdc, int xc, int yc, int A, int B, COLORREF c) {
    double x = 0, y = B;
    Draw4Points(hdc, xc, yc, x, y, c);
    int A2 = A * A;
    int B2 = B * B;

    double d1 = B2 - B * A2;
    double Change1 = 3 * B2 + (2 * A2) * (-B + 1), Change2 = 3 * B2;
    double ChangeInChange1 = 2 * (B2 + A2), ChangeInChange2 = 2 * B2;

    while (x * B2 <= y * A2) {
        if (d1 >= 0) {
            d1 += Change1;
            Change1 += ChangeInChange1;
            y--;
        }
        else{
            d1 += Change2;
            Change1 += ChangeInChange2;
        }
        
        x++;
        Change2 += ChangeInChange2;
        Draw4Points(hdc, xc, yc, Round(x), Round(y), c);
    }
    
    x = A, y = 0;
    double d2 = A2 - (A * B2);
    Change1 = 3 * A2 + (2 * B2) * (-A + 1);
    Change2 = 2 * A2;
    ChangeInChange1 = 2 * (B2 + A2), ChangeInChange2 = 2 * A2;

    while (x * B2 > y * A2) {
        if (d2 >= 0) {
            d2 += Change1;
            Change1 += ChangeInChange1;
            x--;
        }
        else{
            d2 += Change2;
            Change1 += ChangeInChange2;
        }
        Change2 += ChangeInChange2; 
        y++;
        
        Draw4Points(hdc, xc, yc, Round(x), Round(y), c);
    }
}
