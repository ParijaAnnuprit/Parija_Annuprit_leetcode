class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//         brute force using 2 matrices
        
        int n=matrix.size();
        vector<vector<int>>rot(n, vector(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rot[i][j]=matrix[n-j-1][i];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = rot[i][j];
            }
        }
    }
};