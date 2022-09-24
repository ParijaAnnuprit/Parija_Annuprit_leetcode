class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>q;
        vector<int>v;
        for(int i=0;i<arr.size();i++){
            int y = abs(x-arr[i]);
            q.push({y,arr[i]});
            if(q.size()>k) q.pop();
        }
        while(!q.empty()){
            v.push_back(q.top().second);
            q.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};