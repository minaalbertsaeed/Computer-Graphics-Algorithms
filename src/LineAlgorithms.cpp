#include "LineAlgorithms.h"
#include <iostream>



void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Round(double x)
{
	return (int)(x + 0.5);
}

void DrawLineNaive(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c)
{
    //calc the slope
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

    if(dy<=dx){ // slope < 1
        double slope = (double)dy/dx;
        if(x1>x2){
           swap(x1,x2) ;
           swap(y1,y2) ;
        }
        for(int x=x1; x<=x2; x++){
            int y = Round(y1+(x-x1)*slope);
            SetPixel(hdc,x,y,c);
        }
    }else{
        double re_slope = (double)dx/dy;
        if(y1>y2){
           swap(x1,x2) ;
           swap(y1,y2) ;
        }
        for(int y=y1; y<=y2; y++){
            int x = Round(x1+(y-y1)*re_slope);
            SetPixel(hdc,x,y,c);
        }
    }

}

void DrawLineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF color) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	SetPixel(hdc, x1, y1, color);
	if (abs(dx) >= abs(dy)) {
		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		int x = x1;
		double y = y1;
		double m = (double)dy / dx;
		while (x2 > x) {
			x++;
			y += m;
			SetPixel(hdc, x, Round(y), color);
		}
	}
	else {
		if (y1 > y2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		double x = x1;
		int y = y1;
		double mi = (double)dx / dy;
		while (y2 > y) {
			y++;
			x += mi;
			SetPixel(hdc, Round(x), y, color);
		}
	}
}
