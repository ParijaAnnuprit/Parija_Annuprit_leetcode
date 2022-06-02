class Solution {
public:
    int arrangeCoins(int n) {
        long l = 1;
        long h = n;
        long m,curr;
        // if(n == 1)
        //     return n;
        while(l<=h){
            m = l+ ((h-l)/2);
            curr = m*(m+1)/2;
            if((curr < n && ((m+1)*(m+2))/2 > n) || (curr == n) )
                return int(m);
            else if(curr < n)
                l = m+1;
            else if(curr > n)
                h = m-1;
            
        }
        return -1;
    }
};