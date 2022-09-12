class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(200,0);
        vector<vector<int>>adjls(n);
        for(int i=0;i<n;i++){
            for(int j =0; j<n;j++){
                if(isConnected[i][j]==1 && i!=j)
                    adjls[i].push_back(j);
            }
        }
        int count=0;
        int k = adjls.size();
        for(int i=0;i<k;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adjls);
            }
        }
        return count;
    }
    void dfs(int start, vector<int>& vis, vector<vector<int>>& adjls){
        vis[start] = 1;
        for(auto i:adjls[start]){
            if(!vis[i]){
                dfs(i,vis,adjls);
            }
        }
    }
};