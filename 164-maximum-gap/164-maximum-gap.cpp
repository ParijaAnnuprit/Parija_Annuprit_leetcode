class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = 0;
        if(n<2)
        {
        return 0;
        }
        for(int i=0; i<n-1; i++)
        {
        maxi = max(maxi,nums[i+1]-nums[i]);
        }
        return maxi;
        }
};