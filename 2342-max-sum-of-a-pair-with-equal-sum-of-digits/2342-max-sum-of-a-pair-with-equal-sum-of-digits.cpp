class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>>mpp;
        for(auto i:nums){
            string s = to_string(i);
            int sum =0;
            for(auto ch:s){
                sum+=(ch-'0');
            }
            mpp[sum].push(i);
        }
        int maxa = -1;
        for(auto i:mpp){
            if(i.second.size()>=2){
                int add = 0;
                add+=i.second.top();
                i.second.pop();
                add+=i.second.top();
                maxa = max(maxa,add);
            }
        }
        return maxa;
    }
};