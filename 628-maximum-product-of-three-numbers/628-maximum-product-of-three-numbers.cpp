// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         int n = nums.size();
//         if(n==3)
//             return nums[0]*nums[1]*nums[2];
//         sort(nums.begin(),nums.end());
//         if(nums[0]*nums[1]*nums[n-1]> nums[n-1]*nums[n-2]*nums[n-3])
//             return nums[0]*nums[1]*nums[n-1];
//         return nums[n-1]*nums[n-2]*nums[n-3];
//     }
// };

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX;  // smallest
        int min2 = INT_MAX;  // second smallest
        int max1 = INT_MIN;  // largest
        int max2 = INT_MIN;  // second largest
        int max3 = INT_MIN;  // third largest
        if(nums.size()==3)
            return nums[0]*nums[1]*nums[2];
        for(int i:nums){
            if(i<=min1){
                min2 = min1;
                min1 = i;}
            else if(i>=min1 && i<=min2)
                min2 = i;
             if(i>=max1){
                 max3 = max2;
                 max2 = max1;
                 max1 = i;
                 }
             else if(i<=max1 && i>=max2){
                 max3 = max2;
                 max2 = i;
             }
             else if(i<=max2 && i>=max3)
                max3 = i;
        }
        if(min1*min2*max1 > max1*max2*max3)
            return min1*min2*max1;
        return max1*max2*max3;
    }
};