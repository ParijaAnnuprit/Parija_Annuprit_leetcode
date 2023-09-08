class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            mpp[i]=nums[i];
        }
        for(auto i:mpp){
            for(auto j:mpp){
                if(j.second== target-i.second && i.first!=j.first){
                    v.push_back(i.first);
                    v.push_back(j.first);
                    break;
                }
                
            }
            if(v.size()>0)
                break;
        }
        return v;
    }
};