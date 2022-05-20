class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int a = mat.size();
        int b = mat[0].size();
        // int n = a*b
        vector<int>mid;
        vector<vector<int>>reshape(r,vector<int>(c));
        if(a*b != r*c)
            return mat;
        for(int i=0; i<(a*b); i++){
//             always consider columns as base since they are the deciding factor
            reshape[i/c][i%c] = mat[i/b][i%b];
        }
        return reshape;
    }
};