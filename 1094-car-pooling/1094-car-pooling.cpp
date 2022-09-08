class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
        for(int i=0;i<trips.size();i++){
            q.push({trips[i][1],trips[i][0]});
            q.push({trips[i][2], trips[i][0]*(-1)});
        }
        int maxsum = INT_MIN;
        int sum = 0;
        while(q.size()){
            sum+=q.top().second;
            q.pop();
            maxsum = max(maxsum,sum);
        }
        if(maxsum>capacity) return false;
        return true;
    }
};