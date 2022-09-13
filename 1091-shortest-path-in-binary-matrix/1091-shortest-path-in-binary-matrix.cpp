class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>vis(n, vector<int>(n,0));
//         ((x,y),dist);
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vis[0][0]=1;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            if(x==n-1 && y==n-1) return cnt;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nx = x+i;
                    int ny = y+j;
                    int ncnt = cnt+1;
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && !vis[nx][ny]){
                        q.push({{nx,ny},ncnt});
                        vis[nx][ny]=1;
                    }
                }
            }
        }
        return -1;
    }
};