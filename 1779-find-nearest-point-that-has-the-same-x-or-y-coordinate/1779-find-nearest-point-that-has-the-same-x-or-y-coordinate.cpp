class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
//         pair of dist and index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
//         pair of index and dist
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(int i=0;i<points.size();i++){
            if(points[i][0]==x || points[i][1]==y){
                int dist = abs(x-points[i][0]) + abs(y-points[i][1]);
                q.push({dist,i});
            }
        }
        if(q.empty()) return -1;
        int m = q.top().first;
        while(q.size()){
            if(q.top().first != m) break;
            else{
                p.push({q.top().second,q.top().first});
                q.pop();
            }
        }
        return p.top().first;
    }
};