class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mpp;
        int close = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int x= abs(nums[i]-0);
            close = min(close, x);
            mpp[x].push(nums[i]);
        }
        return mpp[close].top();
    }
};