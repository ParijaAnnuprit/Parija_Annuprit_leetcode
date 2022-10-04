class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
//         this is the real sliding window o(n)
        int mini = INT_MAX;
        int j = 0;
        int sum = 0;
        int count =0;
        for(int i=0;i<nums.size();i++){
            int start=i;
            while(j<nums.size() && sum<target){
                sum = sum+nums[j];
                count++;
                j++;
            }
            if(sum>=target) mini = min(mini, count);
            sum-=nums[i];
            count--;
        }
        if(mini == INT_MAX) return 0;
        return mini;
    }
};


// this is not real prefix sum since the time complexity is o(n^2)
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int mini = INT_MAX;
//         for(int i=0;i<nums.size();i++){
//             int j=i;
//             int sum = 0;
//             int count =0;
//             while(j<nums.size() && sum<target){
//                 sum = sum+nums[j];
//                 count++;
//                 j++;
//             }
//             if(sum>=target) mini = min(mini, count);
//         }
//         if(mini == INT_MAX) return 0;
//         return mini;
//     }
// };