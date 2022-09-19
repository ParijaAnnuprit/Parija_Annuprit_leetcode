class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjls(n);
        vector<int>vis(n,0);
        vector<int>res;
        queue<int>q;
        for(int i=0;i<edges.size();i++){
            adjls[edges[i][0]].push_back(edges[i][1]);
            adjls[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                count++;
                int subcount =0;
                q.push(i);
                while(!q.empty()){
                    int x = q.front();
                    subcount++;
                    q.pop();
                    for(int j=0;j<adjls[x].size();j++){
                        if(!vis[adjls[x][j]]){
                            q.push(adjls[x][j]);
                            vis[adjls[x][j]]=1;
                        }
                    }
                }
                res.push_back(subcount);
            }
        }
        if(count==1) return 0;
        long long y = 0;
        long long e = 0;
        for(int k=0;k<res.size();k++){
            y = y+ res[k]*e;
            e+=res[k];
        }
        return y;
    }
};