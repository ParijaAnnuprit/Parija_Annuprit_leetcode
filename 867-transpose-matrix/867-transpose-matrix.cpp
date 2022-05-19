class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r= matrix.size();
        int c = matrix[0].size();
        vector<vector<int>>tp(c, vector<int>(r,0));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                tp[j][i] = matrix[i][j];
            }
        }
        return tp;
    }
};