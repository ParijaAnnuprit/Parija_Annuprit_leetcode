class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int r1 = abs(bx2-bx1)* abs(by2-by1);
        int r2 = abs(ay2-ay1)* abs(ax2-ax1);
        int ta;
        int c1;
        if(ax2<bx1 || ax1>bx2 || ay2<by1 || ay1>by2)
            c1 = 0;
        else{
            c1 = abs(min(ay2,by2) - max(ay1,by1)) * abs(min(ax2,bx2) - max(ax1,bx1));
        }
        ta = r1+r2-c1;
        return ta;
            
    }
};
