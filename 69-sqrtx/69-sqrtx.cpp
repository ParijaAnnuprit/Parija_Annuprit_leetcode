class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        for(long long int i=0; i<=x; i++){
            long long int y = i*i;
            if(y>x)
                return i-1;
        }
        return 0;
    }
};