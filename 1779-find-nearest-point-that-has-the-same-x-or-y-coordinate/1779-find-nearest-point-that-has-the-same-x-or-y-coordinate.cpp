// class Solution {
// public:
//     int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
// //         pair of dist and index
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
// //         pair of index and dist
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
//         for(int i=0;i<points.size();i++){
//             if(points[i][0]==x || points[i][1]==y){
//                 int dist = abs(x-points[i][0]) + abs(y-points[i][1]);
//                 q.push({dist,i});
//             }
//         }
//         if(q.empty()) return -1;
//         int m = q.top().first;
//         while(q.size()){
//             if(q.top().first != m) break;
//             else{
//                 p.push({q.top().second,q.top().first});
//                 q.pop();
//             }
//         }
//         return p.top().first;
//     }
// };

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        pair<int,int>p;
//         dist,ind
        p = {INT_MAX,INT_MAX};
        for(int i=0;i<points.size();i++){
            if(points[i][0]==x || points[i][1]==y){
                int dist = abs(points[i][0]-x)+abs(points[i][1]-y);
                if(dist == p.first) p.second = min(p.second,i);
                else if(dist<p.first){
                    p.first = min(p.first,dist);
                    p.second = i;
                }
            }
        }
        if(p.second == INT_MAX) return -1;
        return p.second;
    }
};