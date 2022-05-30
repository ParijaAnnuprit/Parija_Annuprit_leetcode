class Solution {
public:
    int reverse(int x) {
        vector<int>vect;
        int mx = INT_MAX;
        int mn = INT_MIN;
    
        while(x!=0){
            vect.push_back(x%10);
            x = x/10;
        }
        int n = vect.size();
        long res=0;
        for(int i=0; i<n; i++){
            res = res+ (vect[i]*pow(10,n-i-1));
        }
        if(res>mx || res<mn)
            return 0;
        return res;
        
//            int reverse(int x) {
//         // these are minimun and maximum range of 32 bit integer
//         int mx = INT_MAX;
//         int mn = INT_MIN;

//         // reverse the number
//         long rev = 0;
//         while(x)
//         {
//             int a = x % 10;
//             rev = rev * 10 + a;
//             x = x/10;
//         }
        
//         // check conditions for outside the range
//         if(rev > mx || rev < mn)  
//             return 0;
        
//         return rev;
    // }
    }
};