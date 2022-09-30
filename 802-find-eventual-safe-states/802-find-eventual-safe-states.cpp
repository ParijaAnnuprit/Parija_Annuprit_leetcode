class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//    using the algorithm and concept of detecting a cycle in a directed graph using dfs
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>checksafe(n,0);
        vector<int>safenode;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                checkdfs(i,graph,vis,pathvis,checksafe);
            }
        }
        for(int i=0;i<n;i++){
            if(checksafe[i]==1)
                safenode.push_back(i);
        }
        return safenode;
    }
    bool checkdfs(int node, vector<vector<int>>&graph, vector<int>&vis, vector<int>&pathvis, vector<int>&checksafe){
        vis[node] = 1;
        pathvis[node] = 1;
            for(auto it:graph[node]){
                if(!vis[it]){
                    if(checkdfs(it,graph,vis,pathvis,checksafe)==true) return true;
                }
                else if(vis[it]==1 && pathvis[it]==1) return true;
            }
        checksafe[node] = 1;
        pathvis[node] = 0;
        return false;
    }
};