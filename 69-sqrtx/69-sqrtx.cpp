class Solution {
public:
//     binary search TC- O(n^2) SC- O(1)
    int mySqrt(int x) {
        int l = 0;
        int h = x;
        if(x<2)
            return x;
        while(l<=h){
            long long m = l + ((h-l)/2);
            long long int temp = m*m;
            if(temp>x)
                h = m-1;
            else if(temp<x)
                if((m+1)*(m+1)>x)
                    return m;
                else 
                    l = m+1;
            else if(temp == x)
                return m;
        }
        return 0;
    }
};


//     brute force TC- O(n^2) SC- O(1)
    // int mySqrt(int x) {
    //     if(x==0 || x==1)
    //         return x;
    //     for(long long int i=0; i<=x; i++){
    //         long long int y = i*i;
    //         if(y>x)
    //             return i-1;
    //     }
    //     return 0;
    // }