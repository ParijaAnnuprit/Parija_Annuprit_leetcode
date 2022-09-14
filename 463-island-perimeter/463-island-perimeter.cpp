class Solution {
public:
    vector<vector<int>>check{{0,1},{0,-1},{1,0},{-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,(vector<int>(n,0)));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    break;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            vis[r][c] = 1;
            q.pop();
            int sides = 4;
            for(int i=0;i<check.size();i++){
                int nr = r+check[i][0];
                int nc = c+check[i][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    if(!vis[nr][nc]){
                        sides--;
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                    }
                    else if(vis[nr][nc]) sides--;
                }
            }
            perimeter+=sides;
        }
        return perimeter;
    }
};