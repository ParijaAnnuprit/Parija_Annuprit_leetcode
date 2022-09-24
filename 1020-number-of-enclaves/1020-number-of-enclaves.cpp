class Solution {
public:
    vector<vector<int>>check{{0,1},{0,-1},{1,0},{-1,0}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m =grid.size();
        int n= grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1 && boundary(grid,i,j)){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                while(!q.empty()){
                    int r= q.front().first;
                    int c =q.front().second;
                    q.pop();
                    for(int k=0;k<check.size();k++){
                        int nr = r+check[k][0];
                        int nc = c+check[k][1];
                        if(nr>=0 && nr<m && nc>=0 && nc<n){
                            if(!vis[nr][nc] && grid[nr][nc]==1){
                                q.push({nr,nc});
                                vis[nr][nc]=1;
                            }
                        }
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]) count++;
            }
        }
        return count;
    }
    bool boundary(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i-1<0 || i+1>=m || j-1<0 || j+1>=n){
            return true;
        }
        return false;
    }
};