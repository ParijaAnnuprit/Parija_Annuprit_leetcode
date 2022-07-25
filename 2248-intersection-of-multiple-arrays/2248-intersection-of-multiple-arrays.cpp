class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>res;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mpp[nums[i][j]]++;
            }
        }
        for(auto i:mpp){
            if(i.second == n)
                res.push_back(i.first);
        }
        sort(res.begin(),res.end());
        return res;
    }
};