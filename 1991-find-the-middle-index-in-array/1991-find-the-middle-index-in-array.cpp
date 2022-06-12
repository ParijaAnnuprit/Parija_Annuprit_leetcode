// class Solution {
// public:
//     int findMiddleIndex(vector<int>& nums) {
//         int n = nums.size();
//         int l = 0;
//         int h = n-1;
//         while(l<h){
//             int m = l+((h-l)/2);
//             int lsum = 0;
//             int rsum = 0;
//             for(int i=0; i<m;i++){
//                 lsum+=nums[i];
//             }
//             for(int j=m+1; j<n;j++){
//                 rsum+=nums[j];
//             }
//             if(lsum >= rsum)
//                 h = m;
//             else
//                 l = m+1;
//         }
        
//         return l;
//     }
// };
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int lsum = 0;
        int rsum = 0;
        int tsum = 0;
        for(int i=0; i<n;i++){
            tsum = tsum+nums[i];
        }
        rsum = tsum;
        for(int i=0; i<n;i++){
            rsum = rsum-nums[i];
            if(lsum == rsum)
                return i;
            lsum+=nums[i];
        }
        return -1;
    }
};
