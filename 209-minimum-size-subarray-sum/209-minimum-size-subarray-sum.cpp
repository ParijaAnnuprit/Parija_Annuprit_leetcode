class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
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