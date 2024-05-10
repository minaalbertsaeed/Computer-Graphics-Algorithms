#include "FillingAlgorithms.h"
#include "synchapi.h"
#include "windef.h"
#include "wingdi.h"
#include <iostream>
#include <stack>
#include <queue>

void MyFloodFill(HDC hdc, int x, int y, COLORREF BorderColor, COLORREF FillColor){ 

    std::queue<Point> S;
    // std::stack<Point> S;
    S.push(Point(x,y));
    while (!S.empty()) {
        // Point p = S.top();
        Point p = S.front();
        S.pop();
        COLORREF c = GetPixel(hdc, p.x, p.y);
        if (c == BorderColor || c == FillColor) continue;
        SetPixel(hdc, p.x, p.y, FillColor);
        // Sleep(1);
        S.push(Point(p.x, p.y-1));
        S.push(Point(p.x, p.y+1));
        S.push(Point(p.x-1, p.y));
        S.push(Point(p.x+1, p.y));
    }
}
