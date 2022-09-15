class Solution {
public:
    vector<vector<int>>check{{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        int flag = 0;
        queue<pair<int,int>>q;
        vector<pair<int,int>>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    q.push({i,j});
                    v.push_back({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        vis[x][y] =1;
                        q.pop();
                        for(int k=0;k<check.size();k++){
                            int nr = x+check[k][0];
                            int nc = y+check[k][1];
                            if(nr<0 || nr>=m || nc<0 || nc>=n){
                                flag=1;
                                // break;
                            }
                            else if(!vis[nr][nc] && board[nr][nc]=='O'){
                                q.push({nr,nc});
                                v.push_back({nr,nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                    if(flag==1){
                        flag=0;
                        v.clear();
                    }
                    else{
                        for(int r=0;r<v.size();r++){
                            board[v[r].first][v[r].second] = 'X';
                        }
                        v.clear();
                    }
                }
            }
        }
    }
};