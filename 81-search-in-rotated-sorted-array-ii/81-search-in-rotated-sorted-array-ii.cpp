class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l<=h){
            int m = l+((h-l)/2);
            if(nums[m]==target)
                return true;
            if(nums[l] == nums[m] && nums[m] == nums[h] && l!=h){
                l++;
                h--;
            }
            else if(nums[m]>= nums[l]){
                if(target>=nums[l] && target<=nums[m])
                    h = m-1;
                else
                    l = m+1;
            }
            else{
                if(target<=nums[h] && target>=nums[m])
                    l = m+1;
                else
                    h = m-1;
            }
        }
        return false;
    }
};