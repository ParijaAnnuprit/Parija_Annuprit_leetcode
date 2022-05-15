class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res;
        int s=0;
        int e=nums.size()-1;
        for(int i =0; i<nums.size(); i++){
            nums[i]= nums[i]*nums[i];
        }
        while(s<=e){
            if(nums[s]>nums[e]){
                res.push_back(nums[s]);
                s++;
            }
            else{
                res.push_back(nums[e]);
                e--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};