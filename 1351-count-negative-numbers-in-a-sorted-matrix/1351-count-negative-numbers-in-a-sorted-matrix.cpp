class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int negno = 0;
        int totnegno = 0;
        for(int i=0; i<r; i++){
            int b = 0;
            int e = c-1;
            int m = b + (e-b)/2;
            while(b<=e){
                if(grid[i][m]<0){
                    negno = (c-m);
                    e = m-1;
                }
                 else{
                    b = m+1;
                }
                m = b + (e-b)/2;
            }
            totnegno += negno;
        }
        return totnegno;
    }
};