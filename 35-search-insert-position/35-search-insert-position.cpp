class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int ans = 0;
        while(l<=h){
            int m = l+ ((h-l)/2);
            if(nums[m] == target)
                return m;
            else if(nums[m] > target){
                h = m-1;
                ans = h+1;}
            else if(nums[m] < target){
                l = m+1;
                ans = l;}
        }
        return ans;
    }
};