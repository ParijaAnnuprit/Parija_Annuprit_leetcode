class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[0] && nums[i]!=nums[n-1])
                count++;
        }
        return count;
    }
};