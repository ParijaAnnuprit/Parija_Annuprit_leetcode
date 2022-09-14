class Solution {
public:
    vector<vector<int>>check{{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    int area = 0;
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        area++;
                        q.pop();
                        for(int i=0;i<check.size();i++){
                            int nr = r+check[i][0];
                            int nc = c+check[i][1];
                            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                                q.push({nr,nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                    maxarea = max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};