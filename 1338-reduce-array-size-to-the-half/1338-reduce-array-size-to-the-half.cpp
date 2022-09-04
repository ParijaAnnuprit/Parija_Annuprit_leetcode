class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int x = n;
        int count=0;
        unordered_map<int,int>mpp;
        priority_queue<pair<int,int>>q;
        for(auto i:arr){
            mpp[i]++;
        }
        for(auto i:mpp){
            q.push({i.second,i.first});
        }
        while(!q.empty()){
            x-=q.top().first;
            count++;
            if(x<=n/2) break;
            else q.pop();
        }
        return count;
    }
};