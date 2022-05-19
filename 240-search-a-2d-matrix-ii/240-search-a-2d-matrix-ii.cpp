class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        had to see
        int n = matrix.size();
        int m = matrix[0].size();
        int r = 0;
        int c = m-1;
        while(r<n && c>=0){
            if(matrix[r][c] > target){
                c--;
            }
            else if(matrix[r][c] < target){
                r++;
            }
            else if(matrix[r][c] == target){
                return true;
            }
        }
        return false;
    }
};