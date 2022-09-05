class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mpp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>v;
        for(auto i:mpp){
            reverse(i.second.begin(),i.second.end());
            for(int j=0;j<i.second.size();j++){
                v.push_back(i.second[j]);
            }
        }
        return v;
    }
};