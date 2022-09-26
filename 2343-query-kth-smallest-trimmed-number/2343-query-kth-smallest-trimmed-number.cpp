class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums[0].length();
        vector<int>v;
        for(int i=0;i<queries.size();i++){
            priority_queue<pair<string,int>, vector<pair<string,int>>, greater<pair<string,int>>>q;
            int x = n-queries[i][1];
            int y = queries[i][0];
            for(int j=0;j<nums.size();j++){
                string k = nums[j].substr(x,queries[i][1]);
                q.push({k,j});
                // if(q.size()>queries[i][0]) q.pop();
            }
            while(y>1){
                q.pop();
                y--;
            }
            v.push_back(q.top().second);
        }
        return v;
    }
};