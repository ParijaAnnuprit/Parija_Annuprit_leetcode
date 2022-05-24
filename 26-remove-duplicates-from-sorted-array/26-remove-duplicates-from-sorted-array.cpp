class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int start = 0;
        while(i<n){
            if(i == n-1){
                nums[start] = nums[i];
                i++;
                start++;
            }
            else if(nums[i] == nums[i+1]){
                i++;
            }
            else if (nums[i] != nums[i+1]){
                nums[start] = nums[i];
                i++;
                start++;
            }
        }
        return start;
    }
};