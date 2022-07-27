class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int count=0;
        int cnt =0;
        for(auto i:mpp){
            if(i.second>=2){
                int x= i.second/2;
                i.second-=(2*x);
                count+=x;
            }
            cnt+=i.second;
        }
        res.push_back(count);
        res.push_back(cnt);
        return res;
    }
};