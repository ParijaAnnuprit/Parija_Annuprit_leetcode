class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        stairs(dp,n);
        return dp[n];
    }
    int stairs(vector<int>& dp, int n){
        if(n<=2){
            dp[n] = n;
            return dp[n];
        }
        else if(dp[n]!=-1) return dp[n];
        else {
            dp[n] = stairs(dp,n-1)+stairs(dp,n-2);
            return dp[n];
        }
        return 0;
    }
};