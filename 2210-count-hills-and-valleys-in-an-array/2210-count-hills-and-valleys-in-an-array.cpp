class Solution {
public:
    int countHillValley(vector<int>& nums) {
//         two pointer
        int hav = 0;
        int n = nums.size();
        int i = 1;
        int j = i+1;
        while(j<n){
            while(nums[i]==nums[j] && j<n-1)
                j++;
            if(nums[i]<nums[i-1] && nums[i]<nums[j])
                hav++;
            else if(nums[i]>nums[i-1] && nums[i]>nums[j])
                hav++;
            i = j; 
            j = i+1;
        }
        return hav;
    }
};