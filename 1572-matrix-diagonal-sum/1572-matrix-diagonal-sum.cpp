class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        int i = 0;
        while(i < n){
            int k = mat[i][i] + mat[i][n-i-1];
            sum += k;
            i++;
        }
        if(n%2!=0){
            return sum - mat[n/2][n/2];
        }
        else
            return sum;
    }
};