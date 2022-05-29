class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[n-1];
        }
        for(int i=0; i<n; i++){
            nums[i+1]= nums[i]^nums[i+1];
        }
        return nums[n-1];
    }
};