class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l<=h){
            int m = l+ ((h-l)/2);
            if(nums[m-1]< nums[m] && nums[m]>nums[m+1])
                return m;
            else if(nums[m+1]> nums[m])
                l = m;
            else if(nums[m-1]> nums[m])
                h = m;
            
        }
        return -1;
    }
};