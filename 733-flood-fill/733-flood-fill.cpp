class Solution {
public:
    vector<vector<int>>check{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            q.pop();
            for(int i=0;i<check.size();i++){
                int nr = r+check[i][0];
                int nc = c+check[i][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && image[nr][nc] == x){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }
       return image; 
    }
};