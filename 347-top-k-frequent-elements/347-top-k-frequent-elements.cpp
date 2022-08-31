class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
//         hash map and priority queue
        unordered_map<int,int>mpp;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto i:mpp){
            q.push({i.second, i.first});
        }
        vector<int>v;
        while(k){
            v.push_back(q.top().second);
            q.pop();
            k--;
        }
        return v;
    }
};