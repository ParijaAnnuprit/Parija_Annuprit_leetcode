class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxsum = nums[0];
        if(nums.size() == 0) return 0;
        if(nums.size()==1) return nums[0];
        for(int i=1; i<nums.size(); i++){
            sum = max(nums[i], sum+nums[i]);
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
        
       
};