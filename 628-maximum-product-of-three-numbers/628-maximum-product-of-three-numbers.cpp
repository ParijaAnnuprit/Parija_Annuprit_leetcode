class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int neg = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n==3)
            return nums[0]*nums[1]*nums[2];
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                break;
            else if(nums[i]<0){
                neg++;
            }
        }
        if(neg==0 || neg==1)
            return nums[n-1]*nums[n-2]*nums[n-3];
        else if(neg>1){
            if(nums[0]*nums[1]*nums[n-1]> nums[n-1]*nums[n-2]*nums[n-3])
                return nums[0]*nums[1]*nums[n-1];
        }
        return nums[n-1]*nums[n-2]*nums[n-3];
    }
};