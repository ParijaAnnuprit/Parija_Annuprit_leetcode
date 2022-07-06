class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        
        
        int max_ele=*max_element(nums.begin(),nums.end());
        int min_ele=*min_element(nums.begin(),nums.end());
        int least_difference=(max_ele-k)-(min_ele+k);
        return max(least_difference,0);
        
    }
};