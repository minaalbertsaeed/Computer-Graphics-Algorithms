#include "windef.h"
#include <windows.h>
#include "ClippingAlgorithms.h"

union OutCode getOutCode(int x, int y, int xleft, int xright, int ybottom, int ytop){
    OutCode out;
    out.all = 0;
    if (x < xleft) 
        out.left = 1;
    else if (x > xright) 
        out.right = 1;

    if (y < ybottom)    
        out.bottom = 1;
    else if (y > ytop) 
        out.top = 1;

    return out;
}
void VIntersect(int x1, int y1, int x2, int y2, int xedge, int& xi, int& yi){
    yi = y1 + ((xedge - x1) * (y2 - y1)) / (x2 - x1);
    xi = xedge;
}
void HIntersect(int x1, int y1, int x2, int y2, int yedge, int& xi, int& yi){
    xi = x1 + ((yedge - y1) * (x2 - x1)) / (y2 - y1);
    yi = yedge;
}

bool LineClipping(int& x1, int& y1, int& x2, int& y2, int xleft, int xright, int ybottom, int ytop){
// main algo
    OutCode out1 = getOutCode(x1, y1, xleft, xright, ybottom, ytop);
    OutCode out2 = getOutCode(x2, y2, xleft, xright, ybottom, ytop);
    while (!(out1.all == 0 && out2.all == 0 ) && !(out1.all & out2.all)) {
        if (out1.all) {
            if(out1.left) 
                VIntersect(x1, y1, x2, y2, xleft, x1, y1);
            else if(out1.right)
                VIntersect(x1, y1, x2, y2, xright, x1, y1);
            else if(out1.top)
                HIntersect(x1, y1, x2, y2, ytop, x1, y1);
            else if (out1.bottom)
                HIntersect(x1, y1, x2, y2, ybottom, x1, y1);
            out1 = getOutCode(x1, y1, xleft, xright, ybottom, ytop);
        } else {
            if(out2.left)
                VIntersect(x1, y1, x2, y2, xleft, x2, y2);
            else if (out2.right)
                VIntersect(x1, y1, x2, y2, xright, x2, y2);
            else if (out2.top)
                HIntersect(x1, y1, x2, y2, ytop, x2, y2);
            else
                HIntersect(x1, y1, x2, y2, ybottom, x2, y2);
            out2 = getOutCode(x2, y2, xleft, xright, ybottom, ytop);
        }
    }
    return (!out1.all && !out2.all);

}