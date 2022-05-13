class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minval = INT_MAX;
        int maxdiff = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            minval = min(minval, nums[i]);
            if(nums[i]== minval){
                continue;
            }
            maxdiff = max(maxdiff, nums[i]-minval);
        }
        if(maxdiff == INT_MIN){
            return -1;
        }
        else{
            return maxdiff;
        }
    }
};