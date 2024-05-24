#ifndef clipping
#define clipping
union OutCode{
    struct {unsigned left:1, right:1, top:1, bottom:1;};
    unsigned all:4;
};

union OutCode getOutCode(int x, int y, int xleft, int xright, int ybottom, int ytop);
void VIntersect(int x1, int y1, int x2, int y2, int xedge, int& xi, int& yi);
void HIntersect(int x1, int y1, int x2, int y2, int yedge, int& xi, int& yi);
bool LineClipping(int& x1, int& y1, int& x2, int& y2, int xleft, int xright, int ybottom, int ytop);
#endif