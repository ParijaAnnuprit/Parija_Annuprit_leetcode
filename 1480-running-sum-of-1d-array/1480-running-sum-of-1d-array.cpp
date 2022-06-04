class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
//         prefix sum
        int n = nums.size();
        int k=0;
        for(int i=0;i<n;i++){
            k = k +nums[i];
            nums[i] = k;
        }
        return nums;
    }
};