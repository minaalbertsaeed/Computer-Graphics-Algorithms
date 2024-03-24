#ifndef LineAlgorithms
#define LineAlgorithms

#include <windows.h>

void DrawLineNaive(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);
void DrawLineDDA(HDC hdc, int x1, int y1, int x2, int y2, COLORREF c);

#endif 
