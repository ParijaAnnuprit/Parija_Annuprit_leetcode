class Solution {
public:
    vector<vector<int>>check{{0,1},{0,-1},{1,0},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count= 0;
        vector<vector<int>>vis(row, vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<check.size();i++){
                int r= x+check[i][0];
                int c= y+check[i][1];
                if(r>=0 && r<m && c>=0 && c<n && !vis[r][c] && grid[r][c]=='1'){
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
    }
};