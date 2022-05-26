class Solution {
public:
    int uniquePaths(int m, int n) {
        ////double num = 1;
        double den = 1;
        int k = m+n-2;
        int r = m-1;
        int i=1;
        double up =1 ;
        while(i <= r){
            // num = num * k;
            // den = den * i;
            up = up* (k-r+i)/i;
            
            i++;
        }
        
        return int(up);
    }
};