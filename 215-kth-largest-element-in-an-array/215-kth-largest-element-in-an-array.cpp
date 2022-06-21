class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
//         bubble sort
        int n = nums.size();
        for(int i=0;i<k;i++){
            for(int j=0;j<n-1;j++){
                if(nums[j]>nums[j+1])
                    swap(nums[j],nums[j+1]);
            }
        }
        return nums[n-k];
    }
};