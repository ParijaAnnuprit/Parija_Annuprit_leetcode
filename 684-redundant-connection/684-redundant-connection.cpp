// class Solution {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
// //         check if has cycle (bfs)
//         int n = edges.size()+1;
//         vector<vector<int>>adjls(n);
//         vector<int>vis(n,0);
//         queue<pair<int,int>>q;
//         vector<pair<int,int>>res;
//         for(int i=0;i<edges.size();i++){
//             adjls[edges[i][0]].push_back(edges[i][1]);
//             adjls[edges[i][1]].push_back(edges[i][0]);
//         }
//         q.push({1,-1});
//         vis[1]=1;
//         while(!q.empty()){
//             int node = q.front().first;
//             int prev = q.front().second;
//             q.pop();
//             for(auto i:adjls[node]){
//                 if(!vis[i]){
//                     vis[i] =1;
//                     q.push({i,node});
//                 }
//                 else if(vis[i] && prev!=i){
//                     res.push_back({i,node});
//                 }
//             }
//         }
//         vector<int>v;
//         v.push_back(res[res.size()-1].first);
//         v.push_back(res[res.size()-1].second);
//         return v;
//     }
// };


class Solution {
public:
vector<int> v;
bool hasCycle(int node, int parent,  vector<bool> &seen,vector<vector<int>> &graph) {
    seen[node] = true;
    bool cycleFound = false;
    for (int &neighbor : graph[node]) {
        if (!seen[neighbor]) {
            cycleFound |= hasCycle(neighbor, node,  seen, graph);
        }
        else if (neighbor != parent) {
             
            return true;
        }
    }
   seen[node] = false;
    return false;
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    vector<bool> seen(n, false);
    for (vector<int> &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    
    if(hasCycle(edge[0],-1,seen,graph)) {
        return edge;
    }
    } 
return v;
    }
};