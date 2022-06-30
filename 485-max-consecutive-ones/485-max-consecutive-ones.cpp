// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int n = nums.size();
//         int count =0;
//         int maxcount=0;
//         for(int i=0;i<n-1;i++){
//             if(nums[i]==1 && nums[i+1]==nums[i])
//                 count++;
//             maxcount = max(maxcount,count);
//             if(nums[i]!=1 || nums[i+1]!=nums[i])
//                 count=1;
//         }
//         return maxcount;
//     }
// };
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count=0;
        int maxi=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
                maxi=max(maxi,count);
                count=0;
            }
        }
        maxi=max(maxi,count);
        return maxi;
    }
};