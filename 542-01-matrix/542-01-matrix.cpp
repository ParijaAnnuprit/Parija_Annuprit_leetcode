class Solution {
public:
    vector<vector<int>>check{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        vector<vector<int>>res(r,vector<int>(c,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            res[x][y] = q.front().second;
            q.pop();
            for(int i=0;i<check.size();i++){
                int nr = x+check[i][0];
                int nc = y+ check[i][1];
                if(nr>=0 && nr<r && nc>=0 && nc<c && !vis[nr][nc]){
                    q.push({{nr,nc},res[x][y]+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return res;
    }
};