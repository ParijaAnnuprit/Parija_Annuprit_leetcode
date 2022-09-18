class Solution {
public:
    vector<vector<int>>check{{0,1},{0,-1},{1,0},{-1,0}};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        vector<vector<int>>vis(m,(vector<int>(n,0)));
        queue<pair<int,int>>q;
        int count=0;
        int flag;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                    flag = 0;
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for(int k=0;k<check.size();k++){
                            int nr = r + check[k][0];
                            int nc = c + check[k][1];
                            if(nr>=0 && nr<m && nc>=0 && nc<n){
                                if(!vis[nr][nc] && grid2[nr][nc] && !grid1[nr][nc]){
                                    flag = 1;
                                    q.push({nr,nc});
                                    vis[nr][nc] = 1;
                                }
                                else if(!vis[nr][nc] && grid2[nr][nc] && grid1[nr][nc]){
                                    q.push({nr,nc});
                                    vis[nr][nc] = 1;
                                }
                            }
                        }
                    }
                    if(flag == 0) count++; 
                }
            }
        }
        return count;
    }
};