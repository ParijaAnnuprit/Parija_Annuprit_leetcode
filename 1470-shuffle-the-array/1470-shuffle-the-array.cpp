#include<vector>
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
//         two pointer approach
        int s = nums.size();
        int b = 0;
        int e = n;
        vector<int> k;
        while(b<n){
            k.push_back(nums[b]);
            k.push_back(nums[e]);
            b++;
            e++;
        }
        return k;
    }
};

