class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        if(nums[h]>=nums[l])
            return nums[l];
        while(l<=h){
            int m = l+((h-l)/2);
            if(nums[m] > nums[m+1])
                return nums[m+1];
            if(nums[m] >= nums[l])
                l = m+1;
            else if(nums[m]<= nums[h])
                h = m-1;
        }
        return 0;
    }
};