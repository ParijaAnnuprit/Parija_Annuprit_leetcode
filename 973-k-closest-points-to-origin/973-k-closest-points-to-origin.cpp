// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         unordered_map<double, vector<vector<int>>>mpp;
//         priority_queue<double, vector<double>, greater<double>>q;
//         for(int i=0;i<points.size();i++){
//             double k = sqrt(pow(points[i][0],2)+ pow(points[i][1],2));
//             q.push(k);
//             mpp[k].push_back(points[i]);
//         }
//         vector<vector<int>>v;
//         while(k){
//             for(int i=0;i<mpp[q.top()].size();i++ ){
//                 v.push_back(mpp[q.top()][i]);
//             }
//             q.pop();
//             k--;
//         }
//         return v;
//     }
// };


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>, greater<pair<double,vector<int>>>>q;
        for(int i=0;i<points.size();i++){
            double m = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            q.push({m,points[i]});
        }
        vector<vector<int>>v;
        while(k){
            v.push_back(q.top().second);
            q.pop();
            k--;
        }
        return v;
    }
};