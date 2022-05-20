class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>matrix(m, vector<int>(n));
        vector<vector<int>>empty;
        int len = original.size();
        if(m*n != len)
            return empty;
        for(int i=0; i<len; i++){
            matrix[i/n][i%n] = original[i];
        }
        return matrix;
    }
};