class Solution {
public:
    vector<vector<int>>check{{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int minutes = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2 && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int flag = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j=0;j<check.size();j++){
                    int nr = r+check[j][0];
                    int nc = c+check[j][1];
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        if(!vis[nr][nc] && grid[nr][nc]==1){
                            q.push({nr,nc});
                            vis[nr][nc]=1;
                            grid[nr][nc] = 2;
                            flag=1;
                        }
                    }
                }
                // if(flag==1) minutes++;
            }
            if(flag==1) minutes++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return minutes;
    }
};