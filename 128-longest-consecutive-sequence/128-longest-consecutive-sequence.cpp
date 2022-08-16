class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0) return 0;
        int maxi = 1;
        int interm = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]) continue;
            else if(nums[i+1]!=nums[i]+1) interm =1;
            else if(nums[i+1]==nums[i]+1){
                interm++;
                maxi = max(maxi,interm);
            }
        }
        return maxi;
    }
};