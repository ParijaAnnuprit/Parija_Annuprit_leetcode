class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //int b = 0;
        //int e = m-1;
        for(int i=0; i<n; i++){
            int b=0;
            int e=m-1;
            while(b<=e){
                int mid= b + (e-b)/2;
                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] < target)
                    b = mid+1;
                else
                    e = mid-1;
            }
        }
        return false;
    }
};