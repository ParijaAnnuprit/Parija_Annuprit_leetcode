class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>vect;
        int first = -1;
        int last = -1;
        int l = 0;
        int h = n-1;
        // if(n == 0){
        //     vect.push_back(first);
        //     vect.push_back(last);
        //     return vect;
        // }
         while(l<=h){
            int m = l + ((h-l)/2);
            if(nums[m] == target){
                first = m;
                h = m-1;
            }
            else if(nums[m]>target)
                h = m-1;
            else if(nums[m]< target)
                l = m+1;
        }
        l = 0;
        h = n-1;
         while(l<=h){
            int m = l + ((h-l)/2);
            if(nums[m] == target){
                last = m;
                l = m+1;
            }
            else if(nums[m]>target)
                h = m-1;
            else if(nums[m]< target)
                l = m+1;
        }
        vect.push_back(first);
        vect.push_back(last);
        return vect;
    }
};