// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         dp[0][0] = grid[0][0];
//         int x = pathsum(grid,m-1,n-1,dp)+grid[m][n];
//         return x;
//     }
//     int pathsum(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
//         if(m==0 && n==0) return dp[m][n];
//         else{
//             int x = grid.size();
//             int y = grid[0].size();
//             int i= m-1;
//             int j = n-1;
//             if(i>=0 && i<x && j>=0 && j<y){
//                 dp[m][n] = min(dp[i][n]+grid[m][n] , dp[m][j]+grid[m][n]);
//                 return dp[m][n];
//             }
//             else if(i>=0 && i<x){
//                 dp[m][n] = dp[i][n]+grid[m][n];
//                 return dp[m][n];
//             }
//             else if(j>=0 && j<y){
//                 dp[m][n] = dp[m][j]+grid[m][n];
//                 return dp[m][n];
//             }
//             else return 0;
//         }
//         return 0;
//     }
// };


class Solution {
public:
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + func(i-1, j, grid, dp);
        int left = grid[i][j] + func(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return func(m-1, n-1, grid, dp);
    }
};