    double Pow(double x, int n) {
        long long int y = 1;
        double ans = x;
        if(n==0)
            return 1;
        while(y!=n){
            long long int temp = y;
            y = y+y;
            if(y<n)
                ans = ans*ans;
            else if(y>n){
                y = n-(y-temp);
                ans = ans* Pow(x,y);
            }
        }
        return ans;
    }
class Solution {
public:
    
    double myPow(double x, int n) {
        long long int k = abs(n);
        double a = pow(x,k);
            if(n<0){
                a = 1/a;
                return a;
            }
        return a;
    }
    
};
//         brute force TC -O(n) SC - O(1)
        // double ans = 1.0;
        // if(n==0)
        //     return 1;
        // for(int i=1; i<= abs(n); i++){
        //     ans = ans*x;
        // }
        // if(n<0)
        //     ans = 1/ans;
        // return ans;

