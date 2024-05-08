#ifndef FillingAlgorithms
#define FillingAlgorithms 

#include "windef.h"
#include <windows.h>
#include "../helperFunctions.h"

class Point {
    public:
        int x;
        int y;
        // Default constructor
        Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
};

void MyFloodFill(HDC hdc, int x, int y, COLORREF BorderColor, COLORREF FillColor);

#endif 
