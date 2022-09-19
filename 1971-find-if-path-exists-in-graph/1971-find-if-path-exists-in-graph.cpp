class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adjls(n);
        vector<int>vis(n,0);
        queue<int>q;
        for(int i=0;i<edges.size();i++){
            adjls[edges[i][0]].push_back(edges[i][1]);
            adjls[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            int x = q.front();
            if(x== destination) return true;
            q.pop();
            for(auto i:adjls[x]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return false;
    }
};