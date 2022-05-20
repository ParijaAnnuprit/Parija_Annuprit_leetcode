class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int temp = 0;
        if(n == 0)
            return nums;
        while(s<=e){
            if(nums[s]%2 == 0)
                s++;
            else{
                temp = nums[s];
                nums[s] = nums[e];
                nums[e] = temp;
                e--;
            }
        }
        return nums;
    }
};