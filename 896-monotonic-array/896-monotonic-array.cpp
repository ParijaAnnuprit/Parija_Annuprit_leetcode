class Solution {
public:
//     this problem can be done by using extra an updated array without duplicates but it will increase the space complexity to o(n) but since we want the space complexity to be constant we use what i call the "loop method"
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp1 = nums;
        vector<int>temp2 = nums;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end(), greater<int>());
        if(temp1 == nums || temp2 == nums)
            return true;
        else 
            return false;
        }
};