class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>odd;
        vector<int>even;
        int n = nums.size();
        if(n == 0)
            return nums;
        for(int i=0; i<n; i++){
            if(nums[i]%2 != 0)
                odd.push_back(nums[i]);
            else 
                even.push_back(nums[i]);
        }
        int e=0;
        int o=0;
        for(int j=0; j<n; j++){
            if(j%2 == 0)
                nums[j] = even[e++];
            else
                nums[j] = odd[o++];
        }
        return nums;
    }
};