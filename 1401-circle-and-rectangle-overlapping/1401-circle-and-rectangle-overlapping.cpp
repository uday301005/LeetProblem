class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        int nx,ny;
        if(x>x2) nx =x2;
        else if(x<x1) nx = x1;
        else    nx = x;

        if(y>y2) ny = y2;
        else if(y<y1) ny = y1;
        else   ny = y;
        
       int dis = (x-nx)*(x-nx) + (y-ny)*(y-ny);
       return dis <= r*r ;
    }
};