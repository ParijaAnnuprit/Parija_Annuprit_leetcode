class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
//         wherever there is a sorted array or a possibility of a sorted array always use binary search
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low<high){
            int mid = low + (high-low)/2;
            int count = 0;
            for(int i=0;i<n;i++){
//                 returns a pointer in case of an array or an iterator in case of a vector
            count+= upper_bound(matrix[i].begin(),matrix[i].end(),mid)- matrix[i].begin();
            }
            if(count<k) low = mid+1;
            else high = mid;
        }
        return high;
    }
};