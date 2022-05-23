class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
// this gives wrong answer i.e. [0,1,2,2,3,0,4,2] == output [0,1,2,3,0,4] ==exp [0,1,4,0,3]
        // for(auto i= nums.begin(); i<nums.end(); ++i){
        //     if(*i == val)
        //         nums.erase(i);
        // }
        // int k = nums.size();
        // return k;
        int i =0;
        int start = 0;
        while(i<n){
            if(nums[i]== val)
                i++;
            else
            {nums[start] = nums[i];
            start++;
            i++;}
            }
        return start;
    }
};