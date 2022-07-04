class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ind;
        int maxval=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxval = max(maxval,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxval)
                ind=i;
        }
        for(int i=0;i<nums.size();i++){
            if(i!=ind && nums[i]*2>maxval)
                return -1;
        }
        return ind;
    }
};